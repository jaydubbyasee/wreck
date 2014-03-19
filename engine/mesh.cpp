#include "mesh.h"
#include <fstream>
#include <string>
#include <sstream>

namespace wreck
{

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
}

bool Mesh::load(std::string filename)
{
    std::ifstream file(filename);

    if(!file.good())
    {
        return false;
    }

    std::string line;
    // For each line in file
    while(std::getline(file, line))
    {
        parseLine(line);
    }

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, pos.size()*sizeof(float), &pos[0], GL_STATIC_DRAW);

    // Note: Remember that the glVertexAttribPointer should not be called until after
    // a vertex buffer object has been bound. Otherwise, you may encounter a segfault.
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

//    glGenBuffers(1, &uvbo);
//    glBindBuffer(GL_ARRAY_BUFFER, uvbo);
//    glBufferData(GL_ARRAY_BUFFER, uv.size()*sizeof(float)*2, &uv[0], GL_STATIC_DRAW);

//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    // Index buffer
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, tris.size()*sizeof(uint), &tris[0], GL_STATIC_DRAW);

    return true;
}

void Mesh::parseLine(std::string line)
{
    std::stringstream s(line);
    float v1, v2, v3, v4;
    std::string keyword;

    // Comment
    if(line[0] == '#')
    {
        return;
    }
    // Vertex definition
    else if(line[0] == 'v')
    {
        s >> keyword >> v1 >> v2 >> v3;

        // Position
        if(keyword.compare("v") == 0)
        {
            pos.push_back(v1);
            pos.push_back(v2);
            pos.push_back(v3);
        }
        // Texture/UV coordinates
        else if(keyword.compare("vt") == 0)
        {
            //uv.push_back(glm::vec2(v1, v2));
        }
        // Normal vector
        else if(keyword.compare("vn") == 0)
        {
            //norm.push_back(v1, v2, v3);
        }
    }
    // Face definition
    else if(line[0] == 'f')
    {
        uint i1,i2,i3;
        // For now we'll ignore the fact that there may be uv's or normals
        s >> keyword >> i1 >> i2 >> i3;
        tris.push_back(i1-1);
        tris.push_back(i2-1);
        tris.push_back(i3-1);
    }
    // Ignore any other definitions for now.
}

void Mesh::use()
{
    glBindVertexArray(vao);
}

}
