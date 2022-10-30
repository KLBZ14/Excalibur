#pragma once

#include "Window/Window.h"
#include "Log/Log.h"
#include "Time/Time.h"
#include "Render/BasicShapes/RenderShapes.h"
#include "Render/Shader/Shader.h"
#include "Player/Player.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Excalibur
{
public:
	void Setup();
	void Run();
	void Kill();


private:

	//class objects
	Time time;
	Log log;
	Window window;
	RenderShapes renderShapes;

	Shader shader;
	Shader modelShader;
	Player player;

	//variables
	const int SCR_WIDTH = 1400;
	int SCR_HEIGHT = 900;
	const char* SCR_NAME = "EXCALIBUR";
};
