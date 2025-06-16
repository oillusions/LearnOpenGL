#pragma once
#include <string>

#include "log_record.h"

class IFormatter {
    public:
        std::string virtual format(LogRecord) = 0;
        virtual ~IFormatter() = default;
};
