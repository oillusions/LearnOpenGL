#pragma once
#include "log_record.h"

class IHandler {
    public:
        void virtual publish(LogRecord) = 0;
        void virtual setFilter(std::vector<std::shared_ptr<IFilter>> filters) = 0;
        void virtual setFormatter(std::shared_ptr<IFormatter> formatter) = 0;
        virtual ~IHandler() = default;
};
