#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace wreck
{
    Camera::Camera(float fov, float aspectRatio, float near, float far)
    {
        this->fov = fov;
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
        return transform.getInverseMatrix();
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
                fov,
                aspectRatio,
                near,
                far);

            projectionChanged = false;
        }

        return projection;
    }

    Transform* Camera::getTransform()
    {
        /* If this functions is being called then it is safe to assume that the camera
           is being transformed. */
        viewChanged = true;
        return &transform;
    }
}
