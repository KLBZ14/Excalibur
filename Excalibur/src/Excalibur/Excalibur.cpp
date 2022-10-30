#include "Excalibur.h"





void Excalibur::Setup()
{
	//setup logging system
	log.Init();

	//setup window
	window.setupWindow(SCR_WIDTH, SCR_HEIGHT, SCR_NAME);

	//setup shader
	shader.setupShader("src/Excalibur/Render/Shader/ShaderObjects/basicShader.vert", "src/Excalibur/Render/Shader/ShaderObjects/basicShader.frag");
	modelShader.setupShader("src/Excalibur/Render/Shader/ShaderObjects/modelShader.vert", "src/Excalibur/Render/Shader/ShaderObjects/modelShader.frag");
	
	//setup camera
	player.createCamera(window.getWindow());

	//setup shape renderer
	renderShapes.setupRenderShapes();
}

void Excalibur::Run()
{
	while (!glfwWindowShouldClose(window.getWindow()))
	{
		//clock time
		time.runClock();

		//process input
		player.runEventGather(window.getWindow(), time.getDeltaTime());

		//set view and projection matrix
		player.setViewMatrix(shader, SCR_WIDTH, SCR_HEIGHT);


		//render
		window.clearColor(0.0f, 0.0f, 0.0f, 1.0f);

		//set directional light
		shader.use();
		shader.setVec3("dirLight.ambient", 0.2f, 0.2f, 0.2f);
		shader.setVec3("dirLight.diffuse", 0.5f, 0.5f, 0.5f);
		shader.setVec3("dirLight.specular", 1.0f, 1.0f, 1.0f);
		shader.setVec3("dirLight.color", 1.0f, 1.0f, 1.0f);
		shader.setVec3("dirLight.direction", 1.0f, -3.0f, 2.0f);
		
		//render floor
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.3f));
		shader.setMat4("model", model);
		shader.setVec3("material.ambient", 0.0, 0.1, 0.06);
		shader.setVec3("material.diffuse", 0.0, 0.50980392, 0.50980392);
		shader.setVec3("material.specular", 0.50196078, 0.50196078, 0.50196078);
		shader.setFloat("material.shininess", 0.25);
		renderShapes.DrawSquare(shader);

		//render model





		//swap buffers and poll IO events
		window.swapBuffers(window.getWindow());
	}
}

void Excalibur::Kill()
{
	glfwTerminate();
}
