#include "GameEngine.h"




void GameEngine::setup(int width, int height, const char* name)
{
	//setup logging system
	log.Init();

	//setup window
	window.setupWindow(width, height, name);

}

void GameEngine::Run()
{
	while (!window.windowShouldClose(window.window))
	{
		//process input


		//render


		//swap buffers and poll IO events
		window.swapBuffers(window.window);

	}
}
