#pragma once
#include "Example.h"
class Example7 :
    public Example
{
public:
	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
	void DrawCubeIndex(float distance);
	void DrawCuadIndex(float distance);
	void DrawSphereIndex(float radius, int slices, int stacks);
	void DrawPyramidIndex(float distance);
	void DrawCube(float distance);
	void DrawCuad(float distance);
	void DrawSphere(float radius, int slices, int stacks);
	void DrawPyramid(float distance);
	void Ejercicio1();
	void Ejercicio2();
};

