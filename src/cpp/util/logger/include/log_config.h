#pragma once
#include <memory>
#include <string>
#include <vector>

#include "log_level.h"
#include "log_base_filter.h"
#include "log_base_formatter.h"
#include "log_base_handler.h"

class LogConfig {
    public:
        std::string getName() const {return logger_name_;}
        LogLevel getLevel() const {return minLevel_;}
        std::shared_ptr<IFormatter> getFormatter() const {return formatter_;}
        std::vector<std::shared_ptr<IHandler>> getHandlers() const {return handlers_;}
        std::vector<std::shared_ptr<IFilter>> getFilters() const {return filters_;}

        class Builder {
            public:
                Builder(const Builder&) = delete;
                Builder& operator=(const Builder&) = delete;

                Builder &name(const std::string &logger_name) {
                    config_.logger_name_ = logger_name;

                    return *this;
                }

                Builder &level(LogLevel level) {
                    config_.minLevel_ = level;
                    return *this;
                }

                Builder &formatter(std::shared_ptr<IFormatter> formatter) {
                    config_.formatter_ = formatter;
                    return *this;
                }

                Builder &addHandler(std::shared_ptr<IHandler> handler) {
                    config_.handlers_.push_back(move(handler));
                    return *this;
                }

                Builder &addFilter(std::shared_ptr<IFilter> filter) {
                    config_.filters_.push_back(move(filter));
                    return *this;
                }

                LogConfig build() && {
                    return std::move(config_);
                }

            private:
                LogConfig config_;
        };
    private:
        friend class Builder;

        std::string logger_name_;
        LogLevel minLevel_ = LogLevel_INFO;
        std::shared_ptr<IFormatter> formatter_;
        std::vector<std::shared_ptr<IFilter>> filters_;
        std::vector<std::shared_ptr<IHandler>> handlers_;

};
