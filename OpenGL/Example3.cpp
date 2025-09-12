#include "Example3.h"
#include "IncludeGL.h"
#include "Cubo.h"
#include "Esfera.h"
#include "Piramide.h"


Example3::Example3()
{
}

void Example3::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(50, 50, 50, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}
void Example3::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//Ejercicio1();
	Ejercicio2();
	glFlush();

}


void Example3::KeyboardFunc(unsigned char key, int X, int Y)
{

}


void Example3::Idle()
{

}

void Example3::Ejercicio1()
{
	DrawAxisXYZ();
	DrawGridsXZ();
}

void Example3::Ejercicio2()
{

}

void Example3::DibujarFiguras()
{
	Cuadrado 
}

void Example3::DrawAxisXYZ()
{
	glLineWidth(5.0f);
	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(20.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 20.0f, 0.0f);


	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 20.0f);

	glEnd();
}


void Example3::DrawGridsXZ()
{
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	glColor3f(0.5f, 0.5f, 0.5f);
	for (float i = -100; i <= 100; i += 5)
	{
		glVertex3f(i, 0.0f, -100.0f);
		glVertex3f(i, 0.0f, 100.0f);

		glVertex3f(-100.0f, 0.0f, i);
		glVertex3f(100.0f, 0.0f, i);
	}
	glEnd();
}
