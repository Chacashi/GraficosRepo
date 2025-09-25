#include "Example5.h"
#include "CamaraFPS.h"
#include "IncludeGL.h"	
#include "DirectionLight.h"	
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Cubo.h"
#include "Esfera.h"


Camara* cam2;
Example5::Example5()
{
	newLight = new DirectionLight(GL_LIGHT0);
}

void Example5::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_SMOOTH);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	newLight->enable();
	cam2 = new CamaraFPS(0.0f, 10.0f, 2.0f);

	glMatrixMode(GL_MODELVIEW);


	((DirectionLight*)newLight)->setDirection(Vector3D(0.0f, 0.0f, -1.0f));

}
void Example5::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (cam2) cam2->ApplyView();
	((DirectionLight*)newLight)->apply();
	Ejercicio1();	
	glutSwapBuffers();
}

void Example5::KeyboardFunc(unsigned char key, int X, int Y)
{
	if (cam2) cam2->Keyboard(key);
	switch (key)
	{
	case 'l':
		newLight->setEnabled(!newLight->enabled);
		break;
	}
	glutPostRedisplay();
}
void Example5::Idle()
{

}

void Example5::Ejercicio1()
{
	Cuadrado cuadrado(5);
	glPushMatrix();
	cuadrado.transform.Translate(Vector3D(0, 0, 0));
	cuadrado.transform.Apply();
	cuadrado.Dibujar();
	glPopMatrix();

	Triangulo triangulo(5);
	glPushMatrix();
	triangulo.transform.Translate(Vector3D(-15, 0, 0));
	triangulo.transform.Apply();
	triangulo.Dibujar();
	glPopMatrix();

	Cubo cubo(3);
	glPushMatrix();
	cubo.transform.Translate(Vector3D(20, 0,0));
	cubo.transform.Apply();
	cubo.Dibujar();
	glPopMatrix();

	Esfera esfera(5);
	glPushMatrix();
	esfera.transform.Translate(Vector3D(10, 0, 0));
	esfera.transform.Apply();
	esfera.Dibujar();
	glPopMatrix();
}

void Example5::Ejercicio2()
{
}

void Example5::Ejercicio3()
{
}




