#pragma once
#include "Example.h"
#include "Light.h"

class Example5 :
    public Example
{
	Light* newLight;
	float torusYawDeg = 0.0f;
public:
	Example5();

	virtual void init() override;
	virtual void Render() override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)  override;
	virtual void Idle() override;

	void Ejercicio1();
	void Ejercicio2();
	void Ejercicio3();


};

