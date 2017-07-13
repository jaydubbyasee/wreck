#pragma once

#include <glm/glm.hpp>
#include "entity.h"

namespace wreck
{
	class Light : public Entity
	{
	public:
		Light(glm::vec3 position, glm::vec3 color);
		glm::vec3 getColor();
		void setColor(glm::vec3 color);
		float getIntensity();
		void setIntensity(float intensity);

	private:
		glm::vec3 color;
		float intensity;
	};
}

