#ifndef __WRECK_ENGINE_MESH_H
#define __WRECK_ENGINE_MESH_H

#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <vector>

namespace wreck
{

class Mesh
{

public:
    Mesh();
    ~Mesh();

    bool load(std::string filename);
    void use();
    void parseLine(std::string line);

    std::vector<float> pos;
    std::vector<glm::vec2> uv;
    std::vector<glm::vec3> norm;
    std::vector<uint> tris;

    GLuint vao;
    GLuint vbo;
    GLuint uvbo;
    GLuint indexBuffer;
};

}

#endif // __WRECK_ENGINE_MESH_H
