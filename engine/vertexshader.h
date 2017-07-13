#pragma once

#include "shader.h"

namespace wreck
{
    class VertexShader : public Shader
    {
    public:
        virtual bool load(std::string filename);
    };
}
