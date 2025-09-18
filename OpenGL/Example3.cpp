#include "Example3.h"
#include "IncludeGL.h"
#include "Cubo.h"
#include "Esfera.h"
#include "Piramide.h"
#include "CamaraFPS.h"

Camara* cam;
Example3::Example3()
{
}

void Example3::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);

	// inicializar cámara FPS en el plano XZ
	cam = new CamaraFPS(0.0f, 10.0f, 2.0f);

	glMatrixMode(GL_MODELVIEW);

}
void Example3::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (cam) cam->ApplyView();
	//Ejercicio1();
	//Ejercicio2();
	Ejercicio3();
	glutSwapBuffers();

}


void Example3::KeyboardFunc(unsigned char key, int X, int Y)
{
	if (cam) cam->Keyboard(key);
	glutPostRedisplay();  // pedir redibujar
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
	DibujarFiguras();
}

void Example3::Ejercicio3()
{
	DibujarFiguras();
}

void Example3::DibujarFiguras()
{
	DrawAxisXYZ();
	DrawGridsXZ();

	Cubo cubo(5);
	glPushMatrix();
	cubo.transform.Translate(Vector3D(-20, 0, 0));
	cubo.transform.Apply();   
	cubo.Dibujar();
	glPopMatrix();

	Piramide piramide(5);
	glPushMatrix();
	piramide.transform.Translate(Vector3D(0,0, 50));
	piramide.transform.Apply();
	piramide.Dibujar();
	glPopMatrix();

	Esfera esfera(5);
	glPushMatrix();
	esfera.transform.Translate(Vector3D(15, 0, 15));
	esfera.transform.Apply(); 
	esfera.Dibujar();
	glPopMatrix();



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
