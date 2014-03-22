#include "vertex.h"

namespace wreck
{

Vertex::Vertex(glm::vec3 position)
{
    this->position = position;
    this->normal = glm::vec3(1.0f);
    this->uv = glm::vec2(1.0f);
}

Vertex::Vertex(glm::vec3 position, glm::vec2 uv)
{
    this->position = position;
    this->normal = glm::vec3(1.0f);
    this->uv = uv;
}

Vertex::Vertex(glm::vec3 position, glm::vec3 normal)
{
    this->position = position;
    this->normal = normal;
    this->uv = glm::vec2(1.0f);
}

Vertex::Vertex(glm::vec3 position, glm::vec2 uv, glm::vec3 normal)
{
    this->position = position;
    this->uv = uv;
    this->normal = normal;
}

}
