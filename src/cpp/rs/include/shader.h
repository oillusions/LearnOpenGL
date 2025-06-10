#pragma once

#include <GLInclude.h>

class Shader {
	protected:
		GLint shaderID;
		GLenum const shaderType;
	public:
		Shader(GLenum shaderType);
		void compile(char* data);
		GLenum getShaderType();
		void close();

	~Shader();
};
