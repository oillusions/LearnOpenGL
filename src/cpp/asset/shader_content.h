#pragma once
#include <memory>
#include <string>
#include <utility>

#include "shader.h"


class ShaderContent {
    public:
        explicit ShaderContent(std::string shader_content) : shader_content(move(shader_content)) {

        };
        const std::string& getShaderContent() {return shader_content;};


    private:
        std::string shader_content;
};
