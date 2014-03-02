#include "transform.h"
#include <glm/gtc/matrix_transform.hpp>

namespace wreck
{
	Transform::Transform()
	{
		parent = nullptr;
	}

	void Transform::translate(float x, float y, float z)
	{
		transformMatrix = glm::translate(transformMatrix, glm::vec3(x,y,z));
	}

	void Transform::rotate(float angle, glm::vec3 axis)
	{
		transformMatrix = glm::rotate(transformMatrix, angle, axis);
	}

	void Transform::scale(float x, float y, float z)
	{
		transformMatrix = glm::scale(transformMatrix, glm::vec3(x,y,z));
	}

	glm::vec4 Transform::getLocalPosition()
	{
		// This can be optimized by caching position if it has not been modified.
		return getLocalTransformMatrix() * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	}

	glm::vec4 Transform::getPosition()
	{
		// This can be optimized by caching position if it has not been modified.
		return getTransformMatrix() * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	}

	glm::mat4 Transform::getLocalTransformMatrix()
	{
		return transformMatrix;
	}

	glm::mat4 Transform::getTransformMatrix()
	{
		// For now we'll ignore applying parent transformations.
		return transformMatrix;
	}

	void Transform::setParentTransform(Transform* parent)
	{
		this->parent = parent;
	}
}