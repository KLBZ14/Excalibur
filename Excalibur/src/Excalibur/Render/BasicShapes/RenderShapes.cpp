#include "RenderShapes.h"



Square* RenderShapes::setupSquare()
{
    Square square;
    square.setupMemory();
    return &square;
}

void RenderShapes::DrawSquare(Shader& shader, Square &square)
{
    square.Draw(shader);
}

void RenderShapes::killSquare(Square& square)
{
    square.Kill();
}

Cube* RenderShapes::setupCube()
{
    Cube cube;
    cube.setupMemory();
    return &cube;
}

void RenderShapes::DrawCube(Shader& shader, Cube& cube)
{
    cube.Draw(shader);
}

void RenderShapes::killCube(Cube& cube)
{
    cube.Kill();
}
