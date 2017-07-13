#pragma once

#include <string>
#include <GL/glew.h>

namespace wreck
{
    class Texture
    {
    public:
        Texture();
        ~Texture();

        bool load(std::string filename);
        void use();

    private:
        GLuint texid;
    };
}
