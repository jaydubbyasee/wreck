#include "shaderprogram.h"

namespace wreck
{
	ShaderProgram::ShaderProgram()
	{
		programID = 0;
		vertexShader = nullptr;
		fragmentShader = nullptr;
	}

	ShaderProgram::~ShaderProgram()
	{
		if(GL_TRUE == glIsProgram(programID))
		{
			glDeleteProgram;
		}
	}

	void ShaderProgram::begin()
	{
		glUseProgram(programID);
	}

	void ShaderProgram::end()
	{
		glUseProgram(0);
	}

	void ShaderProgram::setUniformValue(std::string name, float& value)
	{
		GLint uniformLoc = glGetUniformLocation(programID, name.c_str());
		glUniform1f(uniformLoc, value);
	}

	void ShaderProgram::setUniformValue(GLint id, float& value)
	{
		glUniform1f(id, value);
	}

	void ShaderProgram::setUniformValue(GLint id, glm::vec2& value)
	{
		glUniform2fv(id, 1, &value[0]);
	}

	void ShaderProgram::setUniformValue(GLint id, glm::vec3& value)
	{
		glUniform3fv(id, 1, &value[0]);
	}

	void ShaderProgram::setUniformValue(GLint id, glm::vec4& value)
	{
		glUniform4fv(id, 1, &value[0]);
	}

	void ShaderProgram::setUniformValue(GLint id, glm::mat3& value)
	{
		glUniformMatrix3fv(id, 1, GL_FALSE, &value[0][0]);
	}

	void ShaderProgram::setUniformValue(GLint id, glm::mat4& value)
	{
		glUniformMatrix4fv(id, 1, GL_FALSE, &value[0][0]);
	}

	void ShaderProgram::setVertexShader(VertexShader *shader)
	{
		vertexShader = shader;
	}

	void ShaderProgram::setFragmentShader(FragmentShader *shader)
	{
		fragmentShader = shader;
	}

	void ShaderProgram::link()
	{
		GLint program = glCreateProgram();

		if(vertexShader)   glAttachShader(program, vertexShader->getID());
		if(fragmentShader) glAttachShader(program, fragmentShader->getID());

		glLinkProgram(program);

		this->programID = program;
	}

	GLuint ShaderProgram::getID()
	{
		return programID;
	}
}