#include "RenderShapes.h"



void RenderShapes::setupRenderShapes()
{
    square.setupSquare();
    cube.setupCube();
    triangle.setupTriangle();
    pyramid.setupPyramid();
}

RenderShapes::~RenderShapes()
{
    square.Kill();
    cube.Kill();
    triangle.Kill();
    pyramid.Kill();
}


void RenderShapes::DrawSquare(Shader& shader)
{
    square.Draw(shader);
}


void RenderShapes::DrawCube(Shader& shader)
{
    cube.Draw(shader);
}

void RenderShapes::DrawTriangle(Shader& shader)
{
    triangle.Draw(shader);
}

void RenderShapes::DrawPyramid(Shader& shader)
{
    pyramid.Draw(shader);
}