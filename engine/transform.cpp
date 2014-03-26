#include "transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

namespace wreck
{
	Transform::Transform()
	{
		parent = nullptr;
        position = glm::vec3(0.0f, 0.0f, 0.0f);
        rotVec = glm::vec3(0.0f, 0.0f, 0.0f);
        scalevec = glm::vec3(1.0f, 1.0f, 1.0f);
	}

	void Transform::translate(float x, float y, float z)
	{
        position += glm::vec3(x,y,z);
	}

	void Transform::rotate(float angle, glm::vec3 axis)
	{
        orientation = glm::rotate(orientation, angle, axis);
	}

    void Transform::rotate(float x, float y, float z)
    {
       rotVec = rotVec + glm::vec3(x, y, z);
    }

	void Transform::scale(float x, float y, float z)
	{
        scalevec = glm::vec3(scalevec);
	}

    glm::vec3 Transform::getLocalPosition()
	{
        return position;
	}

    glm::vec3 Transform::getPosition()
	{
        return position;
	}

    void Transform::setPosition(float x, float y, float z)
    {
        position = glm::vec3(x,y,z);
    }

    void Transform::setPosition(glm::vec3 position)
    {
        this->position = position;
    }

    glm::mat4 Transform::getMatrix()
	{
        glm::mat4 t = glm::translate(position);
        glm::mat4 ry = glm::rotate(rotVec.y, glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 rx = glm::rotate(rotVec.x, glm::vec3(1.0f, 0.0f, 0.0f));
        glm::mat4 s = glm::scale(scalevec);

        return t * ry* rx * s;
	}

    glm::mat4 Transform::getInverseMatrix()
	{
        return glm::inverse(getMatrix());
	}

    void Transform::setParent(Transform* parent)
	{
		this->parent = parent;
	}

    glm::vec3 Transform::forward()
    {
        glm::mat4 m = getMatrix();
        return glm::vec3(-m[2][0], -m[2][1], -m[2][2]);
    }

    glm::vec3 Transform::right()
    {
        glm::mat4 m = getMatrix();
        return glm::vec3(m[0][0], m[0][1], m[0][2]);
    }

    glm::vec3 Transform::up()
    {
        glm::mat4 m = getMatrix();
        return glm::vec3(m[1][0], m[1][1], m[1][2]);
    }
}
