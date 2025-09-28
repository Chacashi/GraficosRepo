#include "Cubo.h"
#include <GL/glut.h>

void Cubo::Dibujar() {
	AplicarTextura();
	glLineWidth(10.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);

	glVertex3f(lado, lado, lado);
	glVertex3f(lado, -lado, lado);
	glVertex3f(-lado, lado, lado);


	glVertex3f(-lado, -lado, lado);
	glVertex3f(-lado, lado, lado);
	glVertex3f(lado, -lado, lado);


	glVertex3f(lado, lado, -lado);
	glVertex3f(lado, -lado, -lado);
	glVertex3f(-lado, lado, -lado);

	glVertex3f(lado, lado, lado);
	glVertex3f(lado, lado, -lado);
	glVertex3f(lado, -lado, -lado);

	glVertex3f(lado, lado, lado);
	glVertex3f(lado, -lado, lado);
	glVertex3f(lado, -lado, -lado);


	glVertex3f(-lado, lado, lado);
	glVertex3f(-lado, lado, -lado);
	glVertex3f(-lado, -lado, -lado);

	glVertex3f(-lado, lado, lado);
	glVertex3f(-lado, -lado, lado);
	glVertex3f(-lado, -lado, -lado);



	glVertex3f(-lado, -lado, -lado);
	glVertex3f(-lado, lado, -lado);
	glVertex3f(lado, -lado, -lado);


	glVertex3f(lado, lado, lado);
	glVertex3f(-lado, lado, lado);
	glVertex3f(lado, lado, -lado);

	glVertex3f(-lado, lado, lado);
	glVertex3f(lado, lado, -lado);
	glVertex3f(-lado, lado, -lado);


	glVertex3f(lado, -lado, lado);
	glVertex3f(-lado, -lado, lado);
	glVertex3f(lado, -lado, -lado);

	glVertex3f(-lado, -lado, lado);
	glVertex3f(lado, -lado, -lado);
	glVertex3f(-lado, -lado, -lado);

	glEnd();
	DesactivarTextura();
}