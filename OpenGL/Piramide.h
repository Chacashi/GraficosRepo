#pragma once
#include "Figura3D.h"
#include "Triangulo.h"
class Piramide :
    public Figura3D
{
public:
    int altura;

    Piramide(int altura) {
		this->altura = altura;
		transform = Transform();
    }

	void Dibujar() override;
};

