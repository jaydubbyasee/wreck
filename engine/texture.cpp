// Note: This implementation depends on gli version 0.5.1

#include "texture.h"
#include <GL/glew.h>
#include <gli/gli.hpp>

namespace wreck
{
    Texture::Texture()
    {

    }

    Texture::~Texture()
    {

    }

    bool Texture::load(std::string filename)
    {
        gli::texture2d texture(gli::load_dds(filename.c_str()));

        if(texture.empty())
        {
            return false;
        }

        glGenTextures(1, &texid);
        glBindTexture(GL_TEXTURE_2D, texid);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGB,
            texture.extent().x,
			texture.extent().y,
            0,
            GL_BGR,
            GL_UNSIGNED_BYTE,
            texture.data()
        );

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        return true;
    }

    void Texture::use()
    {
        glBindTexture(GL_TEXTURE_2D, texid);
    }
}
