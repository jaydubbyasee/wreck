#ifndef __WRECK_ENGINE_LIGHT_H
#define __WRECK_ENGINE_LIGHT_H

#include <glm/glm.hpp>
#include "engine/entity.h"

namespace wreck
{

class Light : public Entity
{
public:
    Light(glm::vec3 position, glm::vec3 color);
    glm::vec3 getColor();
    void setColor(glm::vec3 color);
    float getIntensity();
    void setIntensity(float intensity);

private:
    glm::vec3 color;
    float intensity;
};

}

#endif // __WRECK_ENGINE_LIGHT_H
