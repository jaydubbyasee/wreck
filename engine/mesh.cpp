#include "mesh.h"
#include <fstream>
#include <string>
#include <sstream>

namespace wreck
{

Mesh::Mesh(std::vector<Vertex> vertexData, std::vector<glm::uint> indices)
{
    this->vertexData = vertexData;
    this->indices = indices;

    updateBindings();
}

Mesh::~Mesh()
{
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);
    glDeleteVertexArrays(1, &vao);
}

void Mesh::updateBindings()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Note: Remember that the glVertexAttribPointer should not be called until after
    // a vertex buffer object has been bound. Otherwise, you may encounter a segfault.
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertexData.size()*sizeof(float)*8, &vertexData[0], GL_STATIC_DRAW);

    // Position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*8, 0);
    // Normal
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float)*8, (void*)12);
    // UV
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float)*8, (void*)24);
    // Index buffer
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(glm::uint), &indices[0], GL_STATIC_DRAW);
}

void Mesh::use()
{
    glBindVertexArray(vao);
}

}
