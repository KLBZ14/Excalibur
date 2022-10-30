#pragma once

#include "Camera/Camera.h"
#include "Excalibur/Window/Window.h"
#include "Excalibur/Render/Shader/Shader.h"


class Player
{
public:
	void createCamera(GLFWwindow* window);
	void setViewMatrix(Shader& shader, int width, int height);
	void runEventGather(GLFWwindow* window, float deltaTime);
	glm::vec3 getPosition();
private:
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 1.0f);
	Camera camera;
};

