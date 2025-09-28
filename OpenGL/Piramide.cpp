#include "Piramide.h"
#include <GL/glut.h>

void Piramide::Dibujar()
{
	AplicarTextura();
	float h = altura;
	float d = altura / 2.0;

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);

	glVertex3f(0, h, 0);
	glVertex3f(-d, 0, d);
	glVertex3f(d, 0, d);

	glVertex3f(0, h, 0);
	glVertex3f(d, 0, d);
	glVertex3f(d, 0, -d);


	glVertex3f(0, h, 0);
	glVertex3f(d, 0, -d);
	glVertex3f(-d, 0, -d);

	glVertex3f(0, h, 0);
	glVertex3f(-d, 0, -d);
	glVertex3f(-d, 0, d);

	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-d, 0, d);
	glVertex3f(d, 0, d);
	glVertex3f(d, 0, -d);
	glVertex3f(-d, 0, -d);
	glEnd();

	DesactivarTextura();
}