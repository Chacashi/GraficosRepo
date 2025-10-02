#pragma once
#include "Example.h"
#include "Figura.h"

class Example6 :
    public Example

{public:
	Example6();

	virtual void init() override;
	virtual void Render() override ;
	virtual void KeyboardFunc(unsigned char key, int X, int Y) override;
	virtual void Idle() override ;

	void DrawAxis(float distance);
	void DrawGrids();
	void DrawCube(float distance);
	void DrawSphere(float radius);
	void DrawSquare(float lado);
	void Ejercicio1();
	void Ejercicio2();
	void Ejercicio3();
	void Ejercicio4();
	void DisplayInstantiate(int num);
	void DisplayCube();
	void DisplaySquare();
	void DisplaySphere();
	void DrawHouse();
	void DrawTree();
	void DrawCar();


};

