#ifndef __WRECK_ENGINE_CAMERA_H
#define __WRECK_ENGINE_CAMERA_H

#include "cameratransform.h"
#include "entity.h"

namespace wreck
{
    class Camera : public Entity
    {
    public:

        /**
         * A constructor.
         */
        Camera(float fov, float aspectRatio, float near, float far);

        /**
         * A destructor.
         */
        ~Camera();

        /**
         * Gets the aspect ratio.
         * @return the aspect ratio.
         */
        float getAspectRatio();

        /**
         * Sets the aspect ratio.
         * @param ratio the aspect ratio.
         */
        void setAspectRatio(float ratio);

        /**
         * Gets the distance of the near plane from the camera position.
         * @return the distance of the near plane.
         */
        float getNear();

        /**
         * Sets the distance of the near plane from the camera position.
         * @param near the distance of the near plane.
         */
        void setNear(float near);

        /**
         * Gets the distance of the far plane from the camera position.
         * @return the distance of the far plane.
         */
        float getFar();

        /**
         * Sets the distance of the far plane from the camera position.
         * @param far the distance of the far plane.
         */
        void setFar(float far);

        /**
         * Gets the view matrix.
         * @return the view matrix.
         */
        glm::mat4 getViewMatrix();

        /**
         * Sets the view matrix.
         * @param view the view matrix.
         */
        void setViewMatrix(glm::mat4 view);

        /**
         * Gets the projection matrix.
         * @return the projection matrix.
         */
        glm::mat4 getProjectionMatrix();

        /**
         * Gets the camera's transform.
         * @return the camera's transform.
         */
        virtual Transform* getTransform();

    private:
        CameraTransform transform;
        glm::mat4 view;
        glm::mat4 projection;
        float fov;
        float aspectRatio;
        float near;
        float far;
        bool viewChanged;
        bool projectionChanged;
    };
}

#endif
