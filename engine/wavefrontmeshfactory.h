#ifndef __WRECK_WAVEFRONTMESHFACTORY_H
#define __WRECK_WAVEFRONTMESHFACTORY_H

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "vertex.h"
#include "mesh.h"

namespace wreck
{

class WavefrontMeshFactory
{
public:
    Mesh* load(std::string filename);
private:
    void parseVertex(std::string& vertToken,
                       const std::vector<glm::vec3>& position,
                       const std::vector<glm::vec2>& uv,
                       const std::vector<glm::vec3>& normal,
                       std::vector<Vertex>& vertexData);
};

}

#endif // __WRECK_WAVEFRONTMESHFACTORY_H
