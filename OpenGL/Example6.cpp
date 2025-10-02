#include "Example6.h"
#include "IncludeGL.h"
GLuint idCubo, idCuadrado, idEsfera;

Example6::Example6()
{
}
void Example6::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(20, 20,20, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	DisplayCube();
	DisplaySquare();
	DisplaySphere();

}
void Example6::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Ejercicio1();
	//Ejercicio2();
	//Ejercicio3();
	Ejercicio4();
	glutSwapBuffers();

}
void Example6::DrawSquare(float lado)
{
	
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(lado, -lado, 0.0f);
	glVertex3f(lado, lado, 0.0f);
	glVertex3f(-lado, lado, 0.0f);
	glVertex3f(-lado, -lado, 0.0f);
	glEnd();

	
}

void Example6::DrawSphere(float radius)
{
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidSphere(radius, 32, 32);
}


void Example6::KeyboardFunc(unsigned char key, int X, int Y)
{

}
void Example6::DrawCube(float distance)
{
	glLineWidth(10.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);

	glVertex3f(distance, distance, distance);
	glVertex3f(distance, -distance, distance);
	glVertex3f(-distance, distance, distance);


	glVertex3f(-distance, -distance, distance);
	glVertex3f(-distance, distance, distance);
	glVertex3f(distance, -distance, distance);


	glVertex3f(distance, distance, -distance);
	glVertex3f(distance, -distance, -distance);
	glVertex3f(-distance, distance, -distance);

	glVertex3f(distance, distance, distance);
	glVertex3f(distance, distance, -distance);
	glVertex3f(distance, -distance, -distance);

	glVertex3f(distance, distance, distance);
	glVertex3f(distance, -distance, distance);
	glVertex3f(distance, -distance, -distance);


	glVertex3f(-distance, distance, distance);
	glVertex3f(-distance, distance, -distance);
	glVertex3f(-distance, -distance, -distance);

	glVertex3f(-distance, distance, distance);
	glVertex3f(-distance, -distance, distance);
	glVertex3f(-distance, -distance, -distance);



	glVertex3f(-distance, -distance, -distance);
	glVertex3f(-distance, distance, -distance);
	glVertex3f(distance, -distance, -distance);


	glVertex3f(distance, distance, distance);
	glVertex3f(-distance, distance, distance);
	glVertex3f(distance, distance, -distance);

	glVertex3f(-distance, distance, distance);
	glVertex3f(distance, distance, -distance);
	glVertex3f(-distance, distance, -distance);


	glVertex3f(distance, -distance, distance);
	glVertex3f(-distance, -distance, distance);
	glVertex3f(distance, -distance, -distance);

	glVertex3f(-distance, -distance, distance);
	glVertex3f(distance, -distance, -distance);
	glVertex3f(-distance, -distance, -distance);

	glEnd();

}

void Example6::Ejercicio1() {
	//DrawCube(5.0f);
	DrawSquare(5.0f);
	//DrawSphere(5.0f);
	
}
void Example6::Ejercicio2() {


	glPushMatrix();
	glTranslatef(-12, 0, 0);
	glCallList(idCubo);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, 0, 0);
	glCallList(idCuadrado);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(10, 0, 0);
	glCallList(idEsfera);
	glPopMatrix();
	
}

void Example6::Ejercicio4() {
	DrawHouse();
	//DrawCar();
	//DrawTree();
}
void Example6::Ejercicio3() {
	DisplayInstantiate(3);
}
void Example6::DisplayInstantiate(int num)
{
	for (int i = 0; i < num; i++) {
		glPushMatrix();
		glTranslatef(i * 2.0f, 0, 0);
		DrawCube(5.0f);
		glPopMatrix();
	}
}
void Example6::DisplayCube()
{
	idCubo = glGenLists(1);
	glNewList(idCubo, GL_COMPILE);
	DrawCube(5.0f);
	glEndList();
}

void Example6::DisplaySquare()
{
	idCuadrado = glGenLists(1);
	glNewList(idCuadrado, GL_COMPILE);
	DrawSquare(5.0f);
	glEndList();
}

void Example6::DisplaySphere()
{

	idEsfera = glGenLists(1);
	glNewList(idEsfera, GL_COMPILE);
	DrawSphere(5.0f);
	glEndList();
}

void Example6::DrawHouse()
{
	glPushMatrix();

	glScalef(1.0f, 0.5f, 1.0f);
	glCallList(idCubo);
	glPopMatrix();

	glPushMatrix();

	glTranslatef(0.0f, 5.0f, 0.0f);
	glScalef(1.2f, 0.5f, 1.2f);
	glColor3f(0.7f, 0.2f, 0.2f);
	glCallList(idCubo);
	glPopMatrix();
}

void Example6::DrawTree()
{
	glPushMatrix();

	glScalef(0.3f, 1.0f, 0.3f);
	glColor3f(0.5f, 0.3f, 0.1f);
	glCallList(idCubo);
	glPopMatrix();

	glPushMatrix();

	glTranslatef(0.0f, 22.0f, 0.0f);
	glColor3f(0.0f, 0.8f, 0.0f);
	glCallList(idEsfera);
	glPopMatrix();
}

void Example6::DrawCar()
{
	glPushMatrix();
	glScalef(2.0f, 0.5f, 1.0f);
	glColor3f(0.2f, 0.2f, 1.0f);
	glCallList(idCubo);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0f, 2.0f, 0.0f);
	glScalef(1.0f, 0.5f, 1.0f);
	glColor3f(0.1f, 0.1f, 0.7f);
	glCallList(idCubo);
	glPopMatrix();


	for (int i = -1; i <= 1; i += 2) {
		for (int j = -1; j <= 1; j += 2) {
			glPushMatrix();
			glTranslatef(i * 4.0f, -2.0f, j * 2.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
			glCallList(idEsfera);
			glPopMatrix();
		}
	}
}

void Example6::Idle()
{

}