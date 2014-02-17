#version 440

layout(location = 0) in vec4 vert;

out vec4 diffuse;

layout(location = 0) uniform mat4 mvp;
layout(location = 1) uniform vec4 inDiffuse;

void main()
{
	gl_Position = mvp * vert;
	//gl_Position = vert;
	diffuse = inDiffuse;
}