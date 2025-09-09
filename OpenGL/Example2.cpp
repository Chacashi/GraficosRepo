#include "Example2.h"
#include "IncludeGL.h"
#include <cmath>
Example2::Example2()
{
}


void Example2::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(50, 50, 50, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}
void Example2::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Ejercicio1();
	glFlush();

}



void Example2::Ejercicio1()
{
	
	DrawCube(7.0f);

}

void Example2::DrawPoint() {

	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.0f);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glScalef(1.0f, 2.0f, 1.0f);

	glPointSize(15.0f);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glPopMatrix();

}

void Example2::DrawCube(float distance)
{
	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.0f);
	glRotatef(270.0f, 0.0f, 0.0f, 1.0f);
	glScalef(1.0f, 2.0f, 1.0f);

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

	glPopMatrix();

		

}





void Example2::DrawLine() {
	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.0f);
	glRotated(45.0f, 0.0f, 0.0f, 1.0f);
	glScalef(10.0f, 2.0f, 1.0f);

	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(20.0f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();
}

void Example2::DrawAxisXY(){

	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.f);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glScalef(10.0f, 2.0f, 1.0f);

	glLineWidth(5.0f);
	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(20.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 20.0f, 0.0f);

	glEnd();

	glPopMatrix();

}

void Example2::DrawAxisXYZ() {

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


	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.f);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glScalef(10.0f, 2.0f, 1.0f);

	glPointSize(50.0f);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();
}

void Example2::Ejercicio2()
{
}

void Example2::Ejercicio3()
{
}


void Example2::KeyboardFunc(unsigned char key, int X, int Y)
{

}


void Example2::Idle()
{

}