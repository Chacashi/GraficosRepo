#pragma once
#include "Figura2D.h"
class Circulo :
    public Figura2D
{
public:
	int radio;
	Circulo(int radio) {
		this->radio = radio;
		transform = Transform();
	}
	void Dibujar() override;


};

