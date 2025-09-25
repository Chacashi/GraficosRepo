#include "Example4.h"
#include "PointLight.h"	
#include "DirectionLight.h"	
#include "SpotLigth.h"
#include "IncludeGL.h"	
#include "CamaraFPS.h"
Camara* cam;
Example4::Example4()
{

	newLight = new DirectionLight(GL_LIGHT0);

}
void Example4::init()
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
	cam = new CamaraFPS(0.0f, 10.0f, 2.0f);

	glMatrixMode(GL_MODELVIEW);


	//((PointLight*)newLight)->setPosition(Vector3D(0.0f, 3.0f, 0.0f));	
	((DirectionLight*)newLight)->setDirection(Vector3D(0.0f, 0.0f, -1.0f));
	/*((SpotLigth*)newLight)->setPosition(Vector3D(0.0f, 20.0f, 0.0f));
	((SpotLigth*)newLight)->setCutoffAngle(30.0f);
	((SpotLigth*)newLight)->setDirection(Vector3D(0.0f, -1.0f, 0.0f));
	((SpotLigth*)newLight)->setExponent(0.0f);
	((SpotLigth*)newLight)->setDiffuse(Color(1.0f, 1.0f, 1.0f, 1.0f));
	((SpotLigth*)newLight)->setSpecular(Color(1.0f, 1.0f, 1.0f, 1.0f));
	((SpotLigth*)newLight)->setAmbient(Color(0.1f, 0.1f, 0.1f, 1.0f));*/
}
void Example4::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Vector3D min = Vector3D(-10.0f, 0.0f, -10.0f);
	Vector3D max = Vector3D(10.0f, 0.0f, 10.0f);
	if (cam) cam->ApplyView();
	((DirectionLight*)newLight)->apply();
	//Example::DrawAxis(10.0f);
	DrawQuadMinMax(min, max);
	DrawTeapot();
	//((PointLight*)newLight)->disable();
	//Example::DrawCube(2.0f);
	//Example::DrawSphere(2.0f);
	glutSwapBuffers();
}


void Example4::KeyboardFunc(unsigned char key, int X, int Y)
{
	if (cam) cam->Keyboard(key);
	switch (key)
	{
	case 'l': 
		newLight->setEnabled(!newLight->enabled);
		break;
	}
	glutPostRedisplay();
}


void Example4::Idle()
{

}

void Example4::DrawQuadMinMax(const Vector3D& min, const Vector3D& max)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	const float y = min.y;

	const float x0 = (min.x < max.x) ? min.x : max.x;
	const float x1 = (min.x > max.x) ? min.x : max.x;
	const float z0 = (min.z < max.z) ? min.z : max.z;
	const float z1 = (min.z > max.z) ? min.z : max.z;

	glNormal3f(0.0f, -1.0f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(x0, y, z0);
	glVertex3f(x1, y, z0);
	glVertex3f(x1, y, z1);
	glVertex3f(x0, y, z1);
	glEnd();
}

void Example4::DrawTorus()
{
	glColor3f(0.2f, 0.2f, 0.8f);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(torusYawDeg, 0.0f, 1.0f, 0.0f);
	glutSolidTorus(1.0, 3.0, 32, 64);
	glPopMatrix();
}

void Example4::DrawTeapot()
{
	glColor3f(0.8f, 0.2f, 0.2f);
	glPushMatrix();
	glTranslatef(5.0f, 2.0f, 0.0f);
	glutSolidTeapot(3.0f);
	glPopMatrix();
}
