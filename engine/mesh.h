#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include "vertex.h"

namespace wreck
{
	class Mesh
	{

	public:
		Mesh(std::vector<Vertex> vertexData, std::vector<uint> indices);
		~Mesh();

		void use();
		void updateBindings();

		std::vector<Vertex> vertexData;
		std::vector<uint> indices;

		GLuint vao;
		GLuint vbo;
		GLuint ibo;
	};
}

