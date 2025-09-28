#pragma once
#include "Example.h"
#include "Light.h"
#include "TextureLoader.h"
#include "Figura.h"
class Example5 :
    public Example
{
	Light* newLight;
	float torusYawDeg = 0.0f;
	TextureLoader* _TextureLoader;
	GLuint texture;
	Figura* shape;
	Figura* shape2;
	Figura* shape3;
	Figura* shape4;
public:
	Example5();

	virtual void init() override;
	virtual void Render() override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)  override;
	virtual void Idle() override;

	void Ejercicio1();
	void Ejercicio2();
	void Ejercicio3();
	void Ejercicio4();
	void Ejercicio5();


};

