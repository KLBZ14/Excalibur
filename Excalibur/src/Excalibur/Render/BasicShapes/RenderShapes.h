#pragma once

#include "Excalibur/Render/Shader/Shader.h"
#include "Shapes.h"



class RenderShapes
{
public:
	void setupRenderShapes();
	~RenderShapes();

	void DrawSquare(Shader& shader);
	void DrawCube(Shader& shader);
	void DrawTriangle(Shader& shader);
	void DrawPyramid(Shader& shader);

private:
	Square square;
	Cube cube;
	Triangle triangle;
	Pyramid pyramid;
};

