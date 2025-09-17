#include "Transform.h"
#include <GL/glut.h>
void Transform::Translate(Vector3D desplazamiento)
{
	posicion = posicion + desplazamiento;
}

void Transform::Rotate( Vector3D eje, float angulo)
{
	rotacion = rotacion + eje * angulo;
}

void Transform::Scale( Vector3D escalar)
{
	escala = Vector3D(escala.x * escalar.x, escala.y* escalar.y
		, escala.z* escalar.z);
}

void Transform::Apply()
{
  
    glTranslatef(posicion.x, posicion.y, posicion.z);


    glRotatef(rotacion.x, 1, 0, 0);
    glRotatef(rotacion.y, 0, 1, 0);
    glRotatef(rotacion.z, 0, 0, 1);


    glScalef(escala.x, escala.y, escala.z);

}
