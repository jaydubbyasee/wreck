#ifndef __WRECK_ENGINE_VERTEX_SHADER_H
#define __WRECK_ENGINE_VERTEX_SHADER_H

#include "shader.h"

namespace wreck
{
	class VertexShader : public Shader
	{
	public:
		virtual bool load(std::string filename);
	};
}

#endif