#pragma once
#include "Figura2D.h"
class Circulo :
    public Figura2D
{
public:
	int radio;
	Circulo(int radio) {
		this->radio = radio;
		this->posicion = Vector3D(0, 0, 0);
		this->escala = Vector3D(1, 1, 1);
		this->rotacion = Vector3D(0, 0, 0);
	}
	void Dibujar() override;


};

