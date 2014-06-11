#ifndef __WRECK_ENGINE_SHADER_PROGRAM_H
#define __WRECK_ENGINE_SHADER_PROGRAM_H

#include "vertexshader.h"
#include "fragmentshader.h"
#include <glm/glm.hpp>

namespace wreck
{
    class ShaderProgram
    {
    public:
        ShaderProgram();
        ~ShaderProgram();

        void begin();
        void end();

        void setUniformValue(std::string name, float& value);
        void setUniformValue(GLint id, float& value);
        void setUniformValue(GLint id, glm::vec2& value);
        void setUniformValue(GLint id, glm::vec3& value);
        void setUniformValue(GLint id, glm::vec4& value);
        void setUniformValue(GLint id, glm::mat3& value);
        void setUniformValue(GLint id, glm::mat4& value);

        void setVertexShader(VertexShader* shader);
        void setFragmentShader(FragmentShader* shader);
        void link();
        GLuint getID();

    private:
        VertexShader* vertexShader;
        FragmentShader* fragmentShader;
        GLuint programID;
    };
}

#endif
