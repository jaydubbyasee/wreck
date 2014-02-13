#ifndef __WRECK_ENGINE_SHADER_H
#define __WRECK_ENGINE_SHADER_H

#include <string>
#include <GL/glew.h>

namespace wreck
{
	enum ShaderType
	{
		VERTEX = GL_VERTEX_SHADER,
		FRAGMENT = GL_FRAGMENT_SHADER
	};

	class Shader
	{
	public:
		virtual ~Shader();
		virtual bool load(std::string filename) = 0;
		GLuint getID();

	protected:
		virtual bool compile(ShaderType st, const std::string& source);
		virtual bool getCompileStatus();
		bool loadFile(std::string filename, std::string& src);
		virtual std::string getCompileErrorMessage();
		GLint id;
	};
}

#endif