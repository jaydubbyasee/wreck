#include "entity.h"

namespace wreck
{

Entity::~Entity()
{
}

Transform* Entity::getTransform()
{
    return &transform;
}

}
