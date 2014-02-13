#ifndef __WRECK_ENGINE_VERTEX_FRAGMENT_H
#define __WRECK_ENGINE_VERTEX_FRAGMENT_H

#include "shader.h"

namespace wreck
{
	class FragmentShader : public Shader
	{
	public:
		virtual bool load(std::string filename);
	};
}

#endif