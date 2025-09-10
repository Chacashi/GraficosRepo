#pragma once
#include <string>
#include "Vector3D.h"
using namespace std;
class Figura
{
	

public:
	Vector3D posicion;
	Vector3D escala;
	Vector3D rotacion;

	virtual void Dibujar() = 0;
};

