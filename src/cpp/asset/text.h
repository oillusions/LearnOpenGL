#pragma once
#include <string>

class Text {
    public:
        explicit Text(std::string text) : data(std::move(text)) {}
        std::string getText() {return data;}
    private:
        std::string data;
};
