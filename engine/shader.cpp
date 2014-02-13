#include "shader.h"
#include <GL/glew.h>
#include <fstream>
#include <iostream>

namespace wreck
{
	Shader::~Shader()
	{
		if(GL_TRUE == glIsShader(id))
		{
			glDeleteShader(id);
		}
	}

	GLuint Shader::getID()
	{
		return id;
	}

	bool Shader::compile(ShaderType st, const std::string& source)
	{
		GLenum err = GL_NO_ERROR;
		GLint compileStatus = GL_FALSE;
		GLuint shader = glCreateShader(st);
		const char* src = source.c_str();
		
		// Binds shader source code to shader
		glShaderSource(shader, 1, &src, NULL);
		err = glGetError();
		if(GL_NO_ERROR != err)
		{
			glDeleteShader(shader);
			return false;
		}

		// Compiles shader and check for compile status
		glCompileShader(shader);
		if(!getCompileStatus())
		{
			glDeleteShader(shader);
			return false;
		}

		this->id = shader;

		return true;
	}

	bool Shader::loadFile(std::string filename, std::string& src)
	{
		std::ifstream file(filename);

		if(!file.good())
		{
			std::cout << "Error: Shader file not found: " << filename << std::endl;
			return false;
		}

		file.seekg(0, std::ios_base::end);
		size_t size = file.tellg();
		src.resize(size, '\0');
		file.seekg(0);
		file.read(&src[0], size);

		return true;
	}

	bool Shader::getCompileStatus()
	{
		GLint compileStatus;
		glGetShaderiv(id, GL_COMPILE_STATUS, &compileStatus);
		if(GL_TRUE != compileStatus)
		{
			return false;
		}

		return true;
	}

	std::string Shader::getCompileErrorMessage()
	{
		GLint logLength = 0;

		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLength);
		std::string log(logLength+1, '\0');
		glGetShaderInfoLog(id, logLength+1, &logLength, &log[0]);

		return log;
	}
}
