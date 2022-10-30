#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Excalibur/Log/Log.h"


class Window
{
public:
	void setupWindow(int width, int height, const char* name);
	void clearColor(float r, float g, float b, float w);
	void swapBuffers(GLFWwindow* window);

	GLFWwindow* getWindow();

	int SCR_WIDTH;
	int SCR_HEIGHT;

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}


private:
	GLFWwindow* window;
};

