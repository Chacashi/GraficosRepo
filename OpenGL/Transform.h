#pragma once
#include "Vector3D.h"
class Transform
{
public:
	Vector3D posicion;
	Vector3D escala;
	Vector3D rotacion;
	Transform() {
		posicion = Vector3D(0, 0, 0);
		escala = Vector3D(1, 1, 1);
		rotacion = Vector3D(0, 0, 0);
	}

	void Translate( Vector3D desplazamiento);
	void Rotate(Vector3D eje, float angulo);
	void Scale(Vector3D escalar);

	void Apply();
};

