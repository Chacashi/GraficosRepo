#pragma once
class Example
{

public:
	Example();
	
	virtual void init() = 0;
	virtual void Render() = 0;
	virtual void KeyboardFunc(unsigned char key, int X, int Y) = 0;
	virtual void Idle() = 0;

	void DrawAxis(float distance);
	void DrawGrids();
	void DrawCube(float distance);
	void DrawSphere(float radius);
};

