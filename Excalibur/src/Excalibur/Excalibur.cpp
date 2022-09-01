#include "Excalibur.h"





void Excalibur::Setup()
{
	//setup logging system
	log.Init();

	//setup window
	window.setupWindow(SCR_WIDTH, SCR_HEIGHT, SCR_NAME);

	//setup shader
	shader.setupShader("src/Excalibur/Render/Shader/ShaderObjects/basicShader.vert", "src/Excalibur/Render/Shader/ShaderObjects/basicShader.frag");

	//setup camera
	camera = Camera(window.getWindow(), glm::vec3(0.0f, 0.0f, 3.0f));

	//setup square
	square = *renderShapes.setupSquare();
}

void Excalibur::Run()
{
	while (!glfwWindowShouldClose(window.getWindow()))
	{
		//time
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		//process input
		input.runEventGather(window.getWindow(), camera, deltaTime);

		// view/projection transformations
		shader.use();
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		shader.setMat4("projection", projection);
		shader.setMat4("view", view);

		//model transformation
		glm::mat4 model = glm::mat4(1.0f);
		shader.setMat4("model", model);


		//render
		window.clearColor(0.9f, 0.9f, 0.9f, 1.0f);
		renderShapes.DrawSquare(shader, square);



		//swap buffers and poll IO events
		window.swapBuffers(window.getWindow());
	}
}

void Excalibur::Kill()
{
	renderShapes.killSquare(square);
	glfwTerminate();
}
