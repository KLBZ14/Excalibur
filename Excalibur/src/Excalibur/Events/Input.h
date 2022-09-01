#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <Excalibur/Camera/Camera.h>


class Input
{
public:
	void runEventGather(GLFWwindow* window, Camera &camera, float deltaTime);


private:

};

