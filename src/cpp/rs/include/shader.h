#pragma once
#include <string>
#include <memory>

#include "glad/glad.h"

class Shader {
    public:
        explicit Shader(GLenum shaderType);
        void compile(const std::string& shader_content) const;
        std::shared_ptr<std::string> getShaderContent() const {return shader_content;};
        GLint getShaderID() const {return shaderID;}
        GLenum getShaderType() const {return shaderType;}
    private:
        GLint shaderID = 0;
        GLenum shaderType;
        std::shared_ptr<std::string> shader_content;
};
