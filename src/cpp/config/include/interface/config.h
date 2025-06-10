#pragma once

template<typename T>
class Config {
    public:
        void virtual load() = 0;
        void virtual save() = 0;
        T virtual getConfig() = 0;
        void virtual updateConfig(T newConfig) = 0;
        void virtual close() = 0;
        virtual ~Config() = default;


};