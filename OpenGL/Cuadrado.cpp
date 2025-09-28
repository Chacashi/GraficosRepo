#include "Cuadrado.h"
#include <GL/glut.h>

int Cuadrado::cambiarTamanio()
{
	return 0;
}

void Cuadrado::Dibujar()
{
	AplicarTextura();
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(lado, -lado, 0.0f);
	glVertex3f(lado, lado, 0.0f);
	glVertex3f(-lado, lado, 0.0f);
	glVertex3f(-lado, -lado, 0.0f);
	glEnd();
	DesactivarTextura();

}
