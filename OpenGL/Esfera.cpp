#include "Esfera.h"
#include <GL/glut.h>
void Esfera::Dibujar()
{
	AplicarTextura();
	glutSolidSphere(radio, 32, 32);

	DesactivarTextura();
}
