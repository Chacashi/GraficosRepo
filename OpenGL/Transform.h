#pragma once
#include "Figura.h"
class Transform
{
public:
	void Translate(Figura& figura, Vector3D);
	void Rotate(Figura& figura, Vector3D eje, float angulo);
	void Scale(Figura& figura, Vector3D escalar);

};

