#pragma once

#include "transform.h"

namespace wreck
{

class Entity
{
public:
    virtual ~Entity();
    virtual Transform* getTransform();

protected:
    Transform transform;
};

}

