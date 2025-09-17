#include "Example3.h"
#include "IncludeGL.h"
#include "Cubo.h"
#include "Esfera.h"
#include "Piramide.h"

float camX = 0.0f;          // posición de la cámara en X
float camY = 1.7f;          // altura de la cámara (ej: altura de un ojo humano)
float camZ = 5.0f;          // posición de la cámara en Z

float camYaw = 0.0f;        // ángulo de rotación horizontal (yaw) en grados
float camPitch = 0.0f;      // (opcional) inclinación vertical de la cámara

float camSpeed = 0.1f;      // velocidad de movimiento (adelante/atrás)
float camTurnSpeed = 2.0f;  // velocidad de giro (izquierda/derecha)
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
	float rad = camYaw * 3.14159265f / 180.0f;

	switch (key)
	{
	case 'w': // adelante
		camX += camSpeed * sinf(rad);
		camZ += -camSpeed * cosf(rad);
		break;
	case 's': // atrás
		camX -= camSpeed * sinf(rad);
		camZ -= -camSpeed * cosf(rad);
		break;
	case 'a': // girar a la izquierda
		camYaw -= camTurnSpeed;
		if (camYaw < 0) camYaw += 360;
		break;
	case 'd': // girar a la derecha
		camYaw += camTurnSpeed;
		if (camYaw >= 360) camYaw -= 360;
		break;
	default:
		break;
	}

	glutPostRedisplay();  // pedir redibujar la escena
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
