#include "shader_loader.h"

#include <utility>

ShaderLoader::ShaderLoader(string shaderFileName, GLenum shaderType):
shader(shaderType), shaderType(shaderType), shaderFileName(std::move(shaderFileName)) {
    ShaderLoader::load();
}

void ShaderLoader::load() {
    if (shaderFileContent == nullptr) {
        if (readShader()) {
            load();
        }
        return;
    }
    shader.compile(shaderFileContent);
}

void ShaderLoader::save() {

}

Shader &ShaderLoader::getConfig() {
    return shader;
}

void ShaderLoader::updateConfig(Shader& newConfig) {

}

void ShaderLoader::close() {
    delete[] shaderFileContent;
}


bool ShaderLoader::readShader() {
    ifstream iShader("assets/shader/" + shaderFileName + "shader");
    if (!iShader.is_open()) {
        cout << "Shader file loading failed[ " << shaderFileName << " ]" << endl;
        return false;
    }
    stringstream shaderStringStream;
    shaderStringStream << iShader.rdbuf();
    iShader.close();
    string str = shaderStringStream.str();

    cout << "Loading " << shaderFileName << endl;
    shaderFileContent = new char[str.size()+ 2];
    memcpy(shaderFileContent, str.c_str(), str.size());
    shaderFileContent[str.size()] = '\0';

    return true;
}



ShaderLoader::~ShaderLoader() {
    ShaderLoader::close();
}

