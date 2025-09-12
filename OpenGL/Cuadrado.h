#pragma once
#include "Figura2D.h"
class Cuadrado :
    public Figura2D
{
public:

	int lado;
	Cuadrado(int lado) {
		this->lado = lado;
	}
	int cambiarTamanio();
	void Dibujar() override;
};

