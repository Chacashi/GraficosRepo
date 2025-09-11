#include "Circulo.h"
#include <GL/glut.h>

void Circulo::Dibujar()
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	const double PI = 3.14159265358979323846;
	for (int i = 0; i <= 30; i++) {
		float angle = 2.0f * PI * i / 30;
		float x = radio * cos(angle);
		float y = radio * sin(angle);
		glVertex2f(x, y);
	}

	glEnd();
}
