#version 440

layout(location = 0) in vec3 modelspace_vertex;
layout(location = 1) in vec3 modelspace_normal;
layout(location = 2) in vec2 uvcoord;

layout(location = 0) uniform mat4 MVP;
layout(location = 1) uniform mat4 M;
layout(location = 2) uniform mat4 V;
layout(location = 3) uniform vec3 lightPos;
layout(location = 4) uniform vec4 lightColor;

out vec2 uv;
out vec3 cameraspace_normal;
out vec3 cameraspace_eyeDirection;
out vec3 cameraspace_lightDirection;
out vec4 LightColor;

void main()
{
    gl_Position = MVP * vec4(modelspace_vertex,1);

    vec3 cameraspace_vertex = (V * M * vec4(modelspace_vertex, 1)).xyz;
    cameraspace_eyeDirection = -cameraspace_vertex;
    cameraspace_normal = (V * M * vec4(modelspace_normal, 0)).xyz;

    vec3 cameraspace_lightPosition = (V * vec4(lightPos, 1)).xyz;
    cameraspace_lightDirection = cameraspace_lightPosition + cameraspace_eyeDirection;
    uv = uvcoord;

    LightColor = lightColor;
}
