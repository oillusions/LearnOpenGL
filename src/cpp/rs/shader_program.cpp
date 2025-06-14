#include "shader_program.h"
#include <iostream>
using namespace std;

ShaderProgram::ShaderProgram(const Shader &vertex_Shader, const Shader &fragment_shader) {
    programID = glCreateProgram();

    glAttachShader(programID, vertex_Shader.getShaderID());
    glAttachShader(programID, fragment_shader.getShaderID());
    glLinkProgram(programID);
    int success;
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (!success) {
        char info_log[512];
        glGetProgramInfoLog(programID, 512, nullptr, info_log);
        cerr << info_log << endl;

    }
}



