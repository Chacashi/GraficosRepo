#include "Example.h"
#include <GL/glut.h>
//#include <stdio.h>

Example::Example()
{
}

void Example::DrawAxis(float distance)
{
	glLineWidth(2.0f);
	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(distance, 0.0f, 0.0f);
	
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, distance, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, distance);
	glEnd();
}

void Example::DrawGrids()
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

