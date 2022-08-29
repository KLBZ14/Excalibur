#pragma once

#include "Window/Window.h"
#include "Log/Log.h"
#include "Events/Input.h"


class GameEngine
{
public:
	void setup(int width, int height, const char* name);
	void Run();
private:
	Log log;
	Window window;
};

