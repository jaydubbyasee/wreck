#include "vertexshader.h"
#include <iostream>

namespace wreck
{
	bool VertexShader::load(std::string filename)
	{
		std::string src;
		if(!loadFile(filename, src))
		{
			return false;
		}

		if(!compile(ShaderType::VERTEX, src))
		{
			std::string err = getCompileErrorMessage();
			std::cout << err << std::endl;
			return false;
		}

		return true;
	}
}