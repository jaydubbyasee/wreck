#include "fragmentshader.h"
#include <iostream>

namespace wreck
{
	bool FragmentShader::load(std::string filename)
	{
		std::string src;
		if(!loadFile(filename, src))
		{
			return false;
		}

		if(!compile(ShaderType::FRAGMENT, src))
		{
			std::string err = getCompileErrorMessage();
			std::cout << err << std::endl;
			return false;
		}

		return true;
	}
}