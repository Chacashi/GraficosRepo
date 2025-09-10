#include "Example2.h"
#include "Cuadrado.h"
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
	//Ejercicio1();
	//Ejercicio2();
	Ejercicio5();

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

void Example2::DrawCubeTransformade(float distance)
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

void Example2::DrawCube(float distance)
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

void Example2::DrawSphere(int radius)
{
	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidSphere(radius, 32, 32);	
}

void Example2::DrawPyramid(float distance)
{
	float h = distance;
	float d = distance / 2.0;

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

}

void Example2::DrawRectangle(float base, float height)
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f); 
	glVertex3f(-base, -height, 0.0f); 
	glVertex3f(base, -height, 0.0f); 
	glVertex3f(base, height, 0.0f); 
	glVertex3f(-base, height, 0.0f); 
	glEnd();

}

void Example2::DrawSquare(int distance)
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(distance, -distance, 0.0f);
	glVertex3f(distance, distance, 0.0f);
	glVertex3f(-distance, distance, 0.0f);
	glVertex3f(-distance, -distance, 0.0f);
	glEnd();


}

void Example2::Circle(float radius, int segments)
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f); 
	glVertex2f(0.0f, 0.0f); 
	const double PI = 3.14159265358979323846;
	for (int i = 0; i <= segments; i++) {
		float angle = 2.0f * PI * i / segments;
		float x = radius * cos(angle);
		float y = radius * sin(angle);
		glVertex2f(x, y);
	}
	
	glEnd();
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

void Example2::Ejercicio5()
{
	Cuadrado cuadrado(5);

	cuadrado.Dibujar();


}


void Example2::KeyboardFunc(unsigned char key, int X, int Y)
{

}


void Example2::Idle()
{

}