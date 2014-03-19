#ifndef __WRECK_ENGINE_VERTEX_H
#define __WRECK_ENGINE_VERTEX_H

#include <glm/glm.hpp>

namespace wreck
{
class Vertex
{
public:
    Vertex(glm::vec3 position);
    Vertex(glm::vec3 position, glm::vec2 uv);
    Vertex(glm::vec3 position, glm::vec3 normal);
    Vertex(glm::vec3 position, glm::vec2 uv, glm::vec3 normal);

    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
};
}


#endif // VERTEX_H
