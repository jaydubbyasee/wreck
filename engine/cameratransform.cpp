#include "cameratransform.h"
#include "glm/detail/type_vec3.hpp"

namespace wreck
{

void CameraTransform::rotate(float x, float y, float z)
{
    this->rotVec = this->rotVec + glm::vec3(x, y, z);

    if(this->rotVec.x >= 3.14f/2.0f)
    {
        this->rotVec.x = 3.14f/2.0f;
    }
    else if(this->rotVec.x <= -3.14f/2.0f)
    {
        this->rotVec.x = -3.14f/2.0f;
    }
}

}
