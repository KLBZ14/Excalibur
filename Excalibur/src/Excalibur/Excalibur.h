#pragma once

#include "Window/Window.h"
#include "Log/Log.h"
#include "Events/Input.h"
#include "Camera/Camera.h"
#include "Render/BasicShapes/RenderShapes.h"
#include "Render/Shader/Shader.h"
#include <future>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

class Excalibur
{
public:
	void Setup();
	void Run();
	void Kill();
private:
	//time
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	//class objects
	Log log;
	Window window;
	Input input;
	RenderShapes renderShapes;
	Shader shader;
	Camera camera;

	//variables
	Square square;
	int SCR_WIDTH = 1400;
	int SCR_HEIGHT = 900;
	const char* SCR_NAME = "EXCALIBUR";


    
};



