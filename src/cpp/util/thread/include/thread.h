#pragma once
#include <thread>
#include <condition_variable>
#include <functional>

#include "thread_state.h"

class Thread {
    public:
        Thread(std::function<void()> work);
        Thread(std::string name, std::function<void(Thread&)> work);

        void wait();
        void notify();

        ThreadState getState() const;

        std::string getName() const {return name;}
    private:
        std::string name;
        std::thread t;
};
