#version 330 core

out vec4 FragColor;

struct DirLight
{
	vec3 direction;
	vec3 color;

};
uniform DirLight dirLight;

void main()
{
	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}