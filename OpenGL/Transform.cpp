#include "Transform.h"

void Transform::Translate(Figura& figura, Vector3D desplazamiento)
{
	figura.posicion = figura.posicion + desplazamiento;
}

void Transform::Rotate(Figura& figura, Vector3D eje, float angulo)
{
	figura.rotacion = figura.rotacion + eje * angulo;
}

void Transform::Scale(Figura& figura, Vector3D escalar)
{
	figura.escala = Vector3D(figura.escala.x * escalar.x, figura.escala.y* escalar.y, figura.escala.z* escalar.z);
}
