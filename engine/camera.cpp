#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace wreck
{
	Camera::Camera(float fov, float aspectRatio, float near, float far)
	{
		this->fieldOfView = fov;
		this->aspectRatio = aspectRatio;
		this->near = 0.1f;
		this->far = 1000.0f;
		this->projectionChanged = true;
		this->viewChanged = true;
	}
	
	Camera::~Camera()
	{

	}

	float Camera::getAspectRatio()
	{
		return aspectRatio;
	}

	void Camera::setAspectRatio(float ratio)
	{
		this->aspectRatio = ratio;
		projectionChanged = true;
	}

	float Camera::getNear()
	{
		return near;
	}

	void Camera::setNear(float near)
	{
		this->near = near;
		projectionChanged = true;
	}

	float Camera::getFar()
	{
		return far;
	}

	void Camera::setFar(float far)
	{
		this->far = far;
		projectionChanged = true;
	}

	glm::mat4 Camera::getViewMatrix()
	{
		// Recompute the view matrix if needed.
		if(viewChanged)
		{
			view = glm::inverse(transform.getTransformMatrix());
			viewChanged = false;
		}

		return view;
	}

	void Camera::setViewMatrix(glm::mat4 view)
	{
		this->view = view;
	}

	glm::mat4 Camera::getProjectionMatrix()
	{
		// Recompute the projection matrix if needed.
		if(projectionChanged)
		{
			projection = glm::perspective(
				fieldOfView,
				aspectRatio,
				near,
				far);
		}

		return projection;
	}

	void Camera::setProjectionMatrix(glm::mat4 projection)
	{
		this->projection = projection;
	}

	Transform* Camera::getTransform()
	{
		/* If this functions is being called then it is safe to assume that the camera 
		   is being transformed. */
		viewChanged = true;
		return &transform;
	}

	void Camera::setTransform(Transform transform)
	{
		this->transform = transform;
		viewChanged = true;
	}
}