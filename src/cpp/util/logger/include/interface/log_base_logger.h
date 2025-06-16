#pragma once
#include <string>

#include "log_level.h"

class ILogger {
    public:
        void virtual log(std::string message, LogLevel level, std::string thread_name) = 0;
        void virtual log(std::string message, LogLevel level) = 0;

        void virtual debug(std::string message) = 0;
        void virtual info(std::string message) = 0;
        void virtual warn(std::string message) = 0;
        void virtual error(std::string message) = 0;

        std::string virtual getName() const = 0;

        virtual ~ILogger() = default;
};
