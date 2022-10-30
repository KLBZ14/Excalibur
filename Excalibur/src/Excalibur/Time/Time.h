#pragma once

#include <GLFW/glfw3.h>


class Time
{
public:
	void runClock()
	{
		//time
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
	}
	float getDeltaTime()
	{
		return deltaTime;
	}
private:
	//time
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
};