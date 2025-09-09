#pragma once
#include "Example.h"
class Example1: public Example
{
public:
	Example1();
	
	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;

	void DrawPoint();
	void DrawLine();
};

