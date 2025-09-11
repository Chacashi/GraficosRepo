#include "Triangulo.h"
#include <GL/glut.h>
void Triangulo::Dibujar()
{
	glBegin(GL_TRIANGLES);

	glVertex3f(0, lado, 0);
	glVertex3f(-lado, 0, lado);
	glVertex3f(lado, 0, lado);

	glEnd();
}
