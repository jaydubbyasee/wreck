#ifndef __WRECK_ENGINE_TRANSFORM_H
#define __WRECK_ENGINE_TRANSFORM_H

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

namespace wreck
{
	/**
	 * Transform is a utility class for generating transformation matrices.
	 *
	 * @author Jonathan Chuong
	 */
	class Transform
	{
	public:
        /**
         * @brief Transform
         */
		Transform();
        virtual ~Transform() {}

		/**
         * @brief translate Translates to position (x,y,z) in local coordinate system.
		 * @param x the amount to translate on the x-axis
		 * @param y the amount to translate on the y-axis
		 * @param z the amount to translate on the z-axis
		 */
        virtual void translate(float x, float y, float z);

        /**
         * @brief rotate Rotates an angle defined in radians around an axis.
         * @param angle the angle of rotation in radians.
         * @param axis the axis of rotation.
         */
        virtual void rotate(float angle, glm::vec3 axis);

        /**
         * @brief rotate
         * @param x
         * @param y
         * @param z
         */
        virtual void rotate(float x, float y, float z);

		/**
         * @brief scale Scales by x,y,z along the x,y,z axes respectively.
		 * @param x the scale factor along the x-axis
		 * @param y the scale factor along the y-axis
		 * @param z the scale factor along the z-axis
		 */
        virtual void scale(float x, float y, float z);

        /**
         * @brief getLocalPosition Gets local position.
         * @return the local position vector.
         */
        virtual glm::vec3 getLocalPosition();

		/**
         * @brief getPosition Gets the position after applying local and parent transformations.
		 * @return the position vector.
		 */
        virtual glm::vec3 getPosition();

        /**
         * @brief setPosition
         * @param x Position on the x-axis.
         * @param y Position on the y-axis.
         * @param z Position on the z-axis.
         */
        virtual void setPosition(float x, float y, float z);

		/**
		 * Gets the local 4x4 transformation matrix.
		 *
		 * @return the local 4x4 transformation matrix.
		 */
        glm::mat4 getMatrix();

		/**
		 * Gets the 4x4 transformation matrix.
		 *
		 * @return the 4x4 transformation matrix.
		 */
        glm::mat4 getInverseMatrix();

        /**
         * @brief getParent
         * @return
         */
        Transform* getParent();

		/**
		 * Sets parent transform.
		 */
        void setParent(Transform* parent);

        /**
         * @brief getRoot
         * @return
         */
        Transform* getRoot();

    protected:
		Transform* parent;
        glm::vec3 position;
        glm::vec3 scalevec;
        glm::vec3 rotVec;
        glm::quat orientation;
	};
}

#endif
