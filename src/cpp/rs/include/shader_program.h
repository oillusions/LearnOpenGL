#pragma once

#include <GLInclude.h>

#include "shader.h"

class ShaderProgram {
        protected:
            static unsigned int shaderProgramID;

        public:
            ShaderProgram(Shader &vertexShader, Shader &fragmentShader);
};
