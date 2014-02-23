#version 440

layout(location = 0) in vec3 vert;
layout(location = 1) in vec2 uvcoord;
out vec2 UV;

layout(location = 0) uniform mat4 mvp;

void main()
{
	gl_Position = mvp * vec4(vert,1);
	UV = uvcoord;
}