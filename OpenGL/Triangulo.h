#pragma once
#include "Figura2D.h"
class Triangulo :
    public Figura2D
{
private:
	int base;
	int altura;
public:
   int 	cambiarTamanio();
};

