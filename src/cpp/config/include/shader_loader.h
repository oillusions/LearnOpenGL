#pragma once

#include <shader.h>
#include "interface/config.h"

class ShaderLoader : public Config<Shader&> {
    private:
        Shader shader;
        GLenum const shaderType;
        string const shaderFileName;
        char* shaderFileContent = nullptr;

        bool readShader();

    public:
        ShaderLoader(string shaderFileName, GLenum shaderType);

        void load() override;
        void save() override;
        Shader& getConfig() override;
        void updateConfig(Shader& newConfig) override;
        void close() override;
        ~ShaderLoader() override;
};