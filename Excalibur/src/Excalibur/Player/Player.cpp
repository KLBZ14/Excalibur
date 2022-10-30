#include "Player.h"

void Player::createCamera(GLFWwindow* window)
{
	camera.setupCamera(window, position);
}

void Player::setViewMatrix(Shader& shader, int width, int height)
{
	// view/projection transformations
	shader.use();
	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)width / (float)height, 0.1f, 100.0f);
	glm::mat4 view = camera.GetViewMatrix();
	shader.setMat4("projection", projection);
	shader.setMat4("view", view);
}


void Player::runEventGather(GLFWwindow* window, float deltaTime)
{
	camera.runEventGather(window, deltaTime);
}

glm::vec3 Player::getPosition()
{
	return camera.cameraPosition;
}

