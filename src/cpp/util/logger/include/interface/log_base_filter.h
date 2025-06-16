#pragma once
#include "log_record.h"

class IFilter {
    public:
        bool virtual filter(LogRecord) = 0;
        virtual ~IFilter() = default;
};
