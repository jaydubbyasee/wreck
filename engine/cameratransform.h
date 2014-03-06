#ifndef __WRECK_ENGINE_CAMERATRANSFORM_H
#define __WRECK_ENGINE_CAMERATRANSFORM_H

#include "transform.h"

namespace wreck
{
class CameraTransform : Transform
{
public:
    CameraTransform();
    ~CameraTransform();

    /**
     * @brief rotate
     * @param x
     * @param y
     * @param z
     */
    void rotate(float x, float y, float z);
};
}

#endif // WRECK_ENGINE_CAMERATRANSFORM_H
