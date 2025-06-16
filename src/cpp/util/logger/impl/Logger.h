#pragma once
#include "log_base_logger.h"
#include "log_config.h"

class Logger : public ILogger {
    public:
        explicit Logger(const LogConfig &config);

        void log(std::string message, LogLevel level, std::string thread_name) override;
        void log(std::string message, LogLevel level) override {log(message, level, "");}

        void debug(std::string message) override {log(message, LogLevel_DEBUG);}
        void info(std::string message) override {log(message, LogLevel_INFO);}
        void warn(std::string message) override {log(message, LogLevel_WARN);}
        void error(std::string message) override {log(message, LogLevel_ERROR);}

        std::string getName() const override {return config_.getName();}
        static long long getTimeStamp();
    private:
        LogConfig config_;
        std::string logger_name;

        void publish(LogRecord record) const;
};
