#pragma once
#include "GameObject.h"
class Character : public GameObject
{
public:

	Character() {
		posicion = Vector3D(0, 0, 0);
		rotacion = Vector3D(0, 0, 0);
		escala = Vector3D(1, 1, 1);
	}
	Character(Figura& figura) {
		posicion = figura.posicion;
		rotacion = figura.rotacion;
		escala = figura.escala;
	}

};

