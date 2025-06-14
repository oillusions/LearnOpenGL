#include "shader.h"
#include "GLInclude.h"
using namespace std;

Shader::Shader(GLenum shaderType) : shaderType(shaderType) {
    shaderID = glCreateShader(shaderType);
}


void Shader::compile(const string& shader_content) const {
    if (shader_content.empty()) {return;}

    char* content = new char[shader_content.size()+ 2];
    memcpy(content, shader_content.c_str(), shader_content.size());
    content[shader_content.size()] = '\0';

    int success;
    glShaderSource(shaderID, 1, &content, nullptr);
    glCompileShader(shaderID);
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info_log[512];
        glGetShaderInfoLog(shaderID, 512, nullptr, info_log);
        cerr << "shader_compile_error: ";
        cerr << info_log << endl;
    }

    delete[] content;
}

