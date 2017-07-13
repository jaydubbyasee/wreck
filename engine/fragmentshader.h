#pragma once

#include "shader.h"

namespace wreck
{
    class FragmentShader : public Shader
    {
    public:
        virtual bool load(std::string filename);
    };
}

