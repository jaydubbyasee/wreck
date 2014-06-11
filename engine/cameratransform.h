#ifndef __WRECK_ENGINE_CAMERATRANSFORM_H
#define __WRECK_ENGINE_CAMERATRANSFORM_H

#include "graphics/transform.h"

namespace wreck
{
class CameraTransform : public Transform
{
public:

    /**
     * @brief rotate
     * @param x
     * @param y
     * @param z
     */
    virtual void rotate(float x, float y, float z);
};
}

#endif // WRECK_ENGINE_CAMERATRANSFORM_H
