#include "logger.h"
#include <chrono>
using namespace std;

Logger::Logger(const LogConfig &config): config_(config) {
    logger_name = config.getName();
    vector<shared_ptr<IFilter>> filters = config.getFilters();
    shared_ptr<IFormatter> formatter = config.getFormatter();

    for (shared_ptr<IHandler> handler : config.getHandlers()) {
        handler->setFilter(filters);
        handler->setFormatter(formatter);
    }
}


void Logger::log(std::string message, LogLevel level, std::string thread_name) {
    long long time_stamp = getTimeStamp();

    LogRecord record(message, time_stamp, level, thread_name, logger_name);
    publish(record);
}

void Logger::publish(LogRecord record) const {
    for (shared_ptr<IHandler> handler : config_.getHandlers()) {
        handler->publish(record);
    }
}


long long Logger::getTimeStamp() {
    auto now = chrono::system_clock::now();
    return chrono::time_point_cast<chrono::milliseconds>(now)
            .time_since_epoch().count();
}
