#ifndef __WRECK_ENGINE_ENTITY_H
#define __WRECK_ENGINE_ENTITY_H

#include "core/transform.h"

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

#endif // __WRECK_ENGINE_ENTITY_H
