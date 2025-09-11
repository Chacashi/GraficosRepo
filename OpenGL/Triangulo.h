#pragma once
#include "Figura2D.h"
class Triangulo :
    public Figura2D
{
public:
	int lado;
	Triangulo(int lado) {
		this->lado = lado;
		this->posicion = Vector3D(0, 0, 0);
		this->escala = Vector3D(1, 1, 1);
		this->rotacion = Vector3D(0, 0, 0);
	}


	void Dibujar() override;


   
};

