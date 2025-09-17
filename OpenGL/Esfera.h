#pragma once
#include "Figura3D.h"
class Esfera :
    public Figura3D
{
public:
    int radio;

    Esfera(int radio) {
        this->radio = radio;
        transform = Transform();
	}

	void Dibujar() override;
};

