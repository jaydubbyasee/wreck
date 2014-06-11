#include "wavefrontmeshfactory.h"
#include "vertex.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

namespace wreck
{

/*
 * Parsing pseudocode
 * For each line
 *  if position, push position
 *  elif texcoord, push texcoord
 *  elif normal, push normal
 *  elif face, look up vertex indices and create vertex from lookup values
 */
Mesh* WavefrontMeshFactory::load(std::string filename)
{
    std::vector<Vertex> vertexData;
    std::vector<uint> indices;
    std::vector<glm::vec3> position;
    std::vector<glm::vec2> uv;
    std::vector<glm::vec3> normal;
    std::map<std::string, uint> vertMap;


    std::ifstream file(filename);
    if(!file.good())
    {
        return nullptr;
    }

    std::string line;
    // For each line in file
    while(std::getline(file, line))
    {
        std::stringstream s(line);
        float v1, v2, v3;

        std::string keyword;

        // Comment
        if(line[0] == '#')
        {
            continue;
        }
        // Vertex definition
        else if(line[0] == 'v')
        {
            s >> keyword >> v1 >> v2 >> v3;

            // Position
            if(keyword.compare("v") == 0)
            {
                position.push_back(glm::vec3(v1, v2, v3));
            }
            // Texture/UV coordinates
            else if(keyword.compare("vt") == 0)
            {
                uv.push_back(glm::vec2(v1, v2));
            }
            // Normal vector
            else if(keyword.compare("vn") == 0)
            {
                normal.push_back(glm::vec3(v1, v2, v3));
            }
        }
        // Face definition
        // For each vertex, perform a lookup to see if it already exists
        // If so, add found index to index buffer
        // Otherwise create vertex and push it to vertex data, push string token to map and set next index.
        else if(line[0] == 'f')
        {
            std::string fv1, fv2, fv3;
            // For now we'll ignore the fact that there may be uv's or normals
            s >> keyword >> fv1 >> fv2 >> fv3;

            processVertex(fv1, position, uv, normal, indices, vertMap, vertexData);
            processVertex(fv2, position, uv, normal, indices, vertMap, vertexData);
            processVertex(fv3, position, uv, normal, indices,  vertMap, vertexData);
        }
        // Ignore any other definitions for now.
    }

    Mesh* mesh = new Mesh(vertexData, indices);

    return mesh;
}

void WavefrontMeshFactory::processVertex(std::string vertToken,
                                         std::vector<glm::vec3>& position,
                                         std::vector<glm::vec2>& uv,
                                         std::vector<glm::vec3>& normal,
                                         std::vector<uint>& indices,
                                         std::map<std::string, uint>& vertMap,
                                         std::vector<Vertex>& vertexData)
{
    if(vertMap.find(vertToken) != vertMap.end())
    {
        indices.push_back(vertMap.at(vertToken));
    }
    else
    {
        parseVertex(vertToken, position, uv, normal, vertexData);
        vertMap[vertToken] = vertexData.size()-1;
        indices.push_back(vertexData.size()-1);
    }
}

void WavefrontMeshFactory::parseVertex(std::string vertToken,
                                         const std::vector<glm::vec3>& position,
                                         const std::vector<glm::vec2>& uv,
                                         const std::vector<glm::vec3>& normal,
                                         std::vector<Vertex>& vertexData)
{
    std::replace(vertToken.begin(), vertToken.end(), '/', ' ');
    std::stringstream vert(vertToken);
    int posInd, uvInd, normInd;

    vert >> posInd >> uvInd >> normInd;

    Vertex vertex(position[posInd-1], uv[uvInd-1], normal[normInd-1]);
    vertexData.push_back(vertex);
}

}

