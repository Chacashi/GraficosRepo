#pragma once
#include "Figura2D.h"
class Triangulo :
    public Figura2D
{
public:
	int base;
	int altura;
	Triangulo(int base, int altura) {
		this->base = base;
		this->altura = altura;
		this->posicion = Vector3D(0, 0, 0);
		this->escala = Vector3D(1, 1, 1);
		this->rotacion = Vector3D(0, 0, 0);
	}


	void Dibujar() override {

	}


   
};

