#pragma once
#include "Figura2D.h"
class Triangulo :
    public Figura2D
{
public:
	int lado;
	Triangulo(int lado) {
		this->lado = lado;
		transform = Transform();
	}


	void Dibujar() override;


   
};

