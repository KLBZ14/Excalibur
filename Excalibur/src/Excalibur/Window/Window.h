#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Excalibur/Log/Log.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Window
{
public:
	void setupWindow(int width, int height, const char* name);
	void clearColor(float r, float g, float b, float w);
	void swapBuffers(GLFWwindow* window);

	GLFWwindow *getWindow();

private:
	GLFWwindow* window;
	
};

