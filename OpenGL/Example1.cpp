#include "Example1.h"
#include "IncludeGL.h"
#include <cmath>
Example1::Example1()
{
}


void Example1::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(200, 200, 200, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}
void Example1::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//DrawPoint();
		//DrawLine();
		//Example::DrawAxis(50.0f);
		//Example::DrawGrids();
	glFlush();
	
}
void Example1::DrawPoint()
{
	glPointSize(15.0f);
	glBegin(GL_POINTS);
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glVertex3d(0.0f, 0.0f, 0.0f);



	//int N = 8;
	//for(int i = 0 ; i<N; i++)
	//	glVertex3d(i, 0.0f, 0.0f);

	//for (int x = 0; x < 360; x++) {
	//	float y = (4 * cos(x)) + (10 * tan(x));
	//	glVertex3d(x, y, 0.0f);
	//}
	//	
	//
		


	glEnd();
}

void Example1::DrawLine()
{
	glLineWidth(50.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 3.0f, 0.0f);

	int J = 10;
	for (int i = 1; i < J; i++) {
		glVertex3f(i, 0.0f, 0.0f);
		glVertex3f(i+1, 0.0f, 0.0f);
	}
	glEnd();
		 
}


void Example1::KeyboardFunc(unsigned char key, int X, int Y)
{

}


void Example1::Idle()
{

}