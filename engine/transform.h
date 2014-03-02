#ifndef __WRECK_ENGINE_TRANSFORM_H
#define __WRECK_ENGINE_TRANSFORM_H

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>

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
		 * A constructor.
		 */
		Transform();

		/**
		 * Translates to position (x,y,z) in local coordinate system.
		 *
		 * @param x the amount to translate on the x-axis
		 * @param y the amount to translate on the y-axis
		 * @param z the amount to translate on the z-axis
		 */
		void translate(float x, float y, float z);

		/**
		 * Rotates an angle defined in radians around an axis.
		 *
		 * @param angle the angle of rotation in radians.
		 * @param axis the axis of rotation.
		 */
		void rotate(float angle, glm::vec3 axis);

		/**
		 * Scales by x,y,z along the x,y,z axes respectively.
		 *
		 * @param x the scale factor along the x-axis
		 * @param y the scale factor along the y-axis
		 * @param z the scale factor along the z-axis
		 */
		void scale(float x, float y, float z);

		/**
		 * Gets local position.
		 *
		 * @return the local position vector.
		 */
		glm::vec4 getLocalPosition();

		/**
		 * Gets the position after applying local and parent transformations.
		 *
		 * @return the position vector.
		 */
		glm::vec4 getPosition();

		/**
		 * Gets the local 4x4 transformation matrix.
		 *
		 * @return the local 4x4 transformation matrix.
		 */
		glm::mat4 getLocalTransformMatrix();

		/**
		 * Gets the 4x4 transformation matrix.
		 *
		 * @return the 4x4 transformation matrix.
		 */
		glm::mat4 getTransformMatrix();

		/**
		 * Sets parent transform.
		 */
		void setParentTransform(Transform* parent);

	private:
		Transform* parent;
		glm::mat4 transformMatrix;
	};
}

#endif