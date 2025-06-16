#pragma once
#include "log_level.h"
#include "thread.h"

class LogRecord {
    public:
        LogRecord(const std::string &message, unsigned long time_stamp, LogLevel level, const std::string &thread_name, std::string logger_name): message_(message),
            time_stamp_(time_stamp), level_(level), thread_name_(thread_name), logger_name_(logger_name) {
        };

        std::string getMessage() const {return message_;}
        long long getTimeStamp() const {return time_stamp_;}
        LogLevel getLevel() const {return level_;}
        std::string getThreadName() const{return thread_name_;}
        std::string getLoggerName() const {return logger_name_;}

    private:
        std::string message_;
        long long time_stamp_;
        LogLevel level_;
        std::string thread_name_;
        std::string logger_name_;
};
