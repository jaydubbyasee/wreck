#version 440

in vec2 uv;
in vec3 cameraspace_normal;
in vec3 cameraspace_eyeDirection;
in vec3 cameraspace_lightDirection;
in vec4 lightColor;

uniform sampler2D texSampler;

out vec4 color;

void main()
{
	vec3 n = normalize(cameraspace_normal);
	vec3 l = normalize(cameraspace_lightDirection);
	float cosTheta = clamp(dot(n,l), 0, 1);

    vec4 material_diffuse = vec4(texture(texSampler, uv).rgb, 1);
    color = vec4(0.2, 0.2, 0.2, 1) + cosTheta * vec4(0.8, 0.2, 0.2, 1) * material_diffuse;
}