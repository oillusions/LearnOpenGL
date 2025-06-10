#include "Shader.h"

Shader::Shader(GLenum shaderType): shaderType(shaderType) {
    this->shaderID = glCreateShader(shaderType);
}

void Shader::compile(char *data) {
    if (data == nullptr) {return;}
    GLboolean success;
    glShaderSource(this->shaderID, 1, &data, nullptr);
    glCompileShader(shaderID);
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, reinterpret_cast<GLint *>(&success));
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(this->shaderID, 512, nullptr, infoLog);
        cout << "shader_compile_error: " << infoLog << endl;
    }
}

Shader::~Shader() {

}





