#pragma once
#include "Figura3D.h"
class Cubo :
    public Figura3D
{
public:

	int lado;
	Cubo(int lado) {
		this->lado = lado;
		transform = Transform();
	}

	void Dibujar() override;
	
};

