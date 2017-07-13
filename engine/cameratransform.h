#pragma once

#include "transform.h"

namespace wreck
{
	class CameraTransform : public Transform
	{
	public:

		/**
		 * @brief rotate
		 * @param x
		 * @param y
		 * @param z
		 */
		virtual void rotate(float x, float y, float z);
	};
}

