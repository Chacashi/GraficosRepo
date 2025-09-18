#pragma once
#include "Example.h"
class Example3 :
    public Example
{

public:

	Example3();

	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;

	
	void Ejercicio1();
	void Ejercicio2();
	void Ejercicio3();

	void DibujarFiguras();
	void DrawAxisXYZ();
	void DrawGridsXZ();
	


};

