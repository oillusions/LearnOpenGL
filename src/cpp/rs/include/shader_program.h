#pragma once
#include "shader.h"

class ShaderProgram {
    public:
        ShaderProgram() = default;
        ShaderProgram(const Shader& vertex_Shader, const Shader& fragment_shader);
        GLint getProgramID() const {return programID;}
    private:
        GLint programID{};
};
