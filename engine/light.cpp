#include "light.h"

namespace wreck
{

Light::Light(glm::vec3 position, glm::vec3 color)
{
    transform.setPosition(position);
    this->color = color;
}

glm::vec3 Light::getColor()
{
    return color;
}

void Light::setColor(glm::vec3 color)
{
    this->color = color;
}

float Light::getIntensity()
{
    return intensity;
}

void Light::setIntensity(float intensity)
{
    this->intensity = intensity;
}

}
