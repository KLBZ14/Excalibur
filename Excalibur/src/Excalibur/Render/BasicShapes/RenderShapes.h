#pragma once

#include "Excalibur/Render/Shader/Shader.h"
#include "Shapes.h"



class RenderShapes
{
public:
	Square* setupSquare();
	void DrawSquare(Shader& shader, Square& square);
	void killSquare(Square& square);

	Cube* setupCube();
	void DrawCube(Shader& shader, Cube& cube);
	void killCube(Cube& cube);
};

