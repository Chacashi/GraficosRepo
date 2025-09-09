#pragma once
#include "Figura2D.h"
class Cuadrado :
    public Figura2D
{
private:
	int lado;

public:
	int cambiarTamanio();
};

