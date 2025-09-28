#include "Example5.h"
#include "CamaraFPS.h"
#include "IncludeGL.h"	
#include "DirectionLight.h"	
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Cubo.h"
#include "Esfera.h"
#include "TextureManager.h"

Camara* cam2;
TextureManager* texManager;
GLuint texture, texture2, texture3, texture4;
float rotX = 0.0f, rotY = 0.0f;
float trasX = 0.0f, trasY = 0.0f, trasZ = -20.0f;
float escala = 1.0f;
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

	shape = new Cubo(2);
	shape2 = new Cuadrado(2);
	shape3 = new Triangulo(5);
	shape4 = new Esfera(5);

	texManager = new TextureManager();
	texture = texManager->LoadBMP("./Textures/barcos.bmp");
	texture2 = texManager->LoadBMP("./Textures/karboncito.bmp");
	texture3 = texManager->LoadBMP("./Textures/chuponcito.bmp");
	texture4 = texManager->LoadBMP("./Textures/chupetin.bmp");
	((DirectionLight*)newLight)->setDirection(Vector3D(0.0f, 0.0f, -1.0f));

}
void Example5::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (cam2) cam2->ApplyView();
	((DirectionLight*)newLight)->apply();

	glTranslatef(trasX, trasY, trasZ);
	glScalef(escala, escala, escala);
	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0);

	Ejercicio5();




	glutSwapBuffers();
}

void Example5::KeyboardFunc(unsigned char key, int X, int Y)
{
	switch (key)
	{

	case 'x': rotX += 5.0f; break;
	case 'y': rotY += 5.0f; break;


	case 'w': trasY += 1.0f; break;
	case 's': trasY -= 1.0f; break;
	case 'a': trasX -= 1.0f; break;
	case 'd': trasX += 1.0f; break;
	case 'q': trasZ += 1.0f; break; // acercar
	case 'e': trasZ -= 1.0f; break; // alejar


	case '+': escala *= 1.1f; break;
	case '-': escala *= 0.9f; break;

	
	case 'l': newLight->setEnabled(!newLight->enabled); break;
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
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S); 
	glEnable(GL_TEXTURE_GEN_T);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texture);

	glPushMatrix();
	((Cubo*)shape)->Dibujar();
	glPopMatrix();

	glDisable(GL_TEXTURE_GEN_S); 
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers(); 
}

void Example5::Ejercicio3()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 

	// Cubo con barcos.bmp
	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	((Cubo*)shape)->Dibujar();
	glPopMatrix();

	// Cuadrado con karboncito.bmp
	glBindTexture(GL_TEXTURE_2D, texture2);
	glPushMatrix();
	glTranslatef(-10.0f, 0.0f, 0.0f);
	((Cuadrado*)shape2)->Dibujar();
	glPopMatrix();

	// Triángulo con chuponcito.bmp
	glBindTexture(GL_TEXTURE_2D, texture3);
	glPushMatrix();
	glTranslatef(20.0f, 0.0f, 0.0f);
	((Triangulo*)shape3)->Dibujar();
	glPopMatrix();

	// Esfera con chupetin.bmp
	glBindTexture(GL_TEXTURE_2D, texture4);
	glPushMatrix();
	glTranslatef(10.0f, 0.0f, 0.0f);
	((Esfera*)shape4)->Dibujar();
	glPopMatrix();

	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_2D);
}

void Example5::Ejercicio4()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	Cubo cubo(3);
	cubo.CargarTextura("./Textures/barcos.bmp", texManager);
	cubo.transform.Translate(Vector3D(0, 0, 0));

	glPushMatrix();
	cubo.transform.Apply();
	cubo.Dibujar();
	glPopMatrix();
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_2D);
}

void Example5::Ejercicio5()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	Cubo cubo(3);
	cubo.CargarTextura("./Textures/barcos.bmp", texManager);
	cubo.transform.Translate(Vector3D(0, 0, 0));

	glPushMatrix();
	cubo.transform.Apply();
	cubo.Dibujar();
	glPopMatrix();

	// Cuadrado con karboncito.bmp
	Cuadrado cuadrado(5);
	cuadrado.CargarTextura("./Textures/karboncito.bmp", texManager);
	cuadrado.transform.Translate(Vector3D ( - 10.0f, 0.0f, 0.0f));
	glPushMatrix();
	cuadrado.transform.Apply();
	cuadrado.Dibujar();
	glPopMatrix();

	// Triángulo con chuponcito.bmp
	Triangulo triangulo(5);
	triangulo.CargarTextura("./Textures/chuponcito.bmp", texManager);
	triangulo.transform.Translate(Vector3D(20.0f, 0.0f, 0.0f));
	glPushMatrix();
	triangulo.transform.Apply();
	triangulo.Dibujar();
	glPopMatrix();


	// Esfera con chupetin.bmp
	Esfera esfera(5);
	esfera.CargarTextura("./Textures/chupetin.bmp", texManager);
	esfera.transform.Translate(Vector3D(10.0f, 0.0f, 0.0f));
	glPushMatrix();
	esfera.transform.Apply();
	esfera.Dibujar();
	glPopMatrix();

	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_2D);
	
}




