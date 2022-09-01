#version 330 core

layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;

void main()
{
	gl_Position = view * perspective * model * vec4(aPos.x, aPos.y, aPos.z, 1.0f);
}