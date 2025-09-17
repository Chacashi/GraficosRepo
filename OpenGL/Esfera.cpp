#include "Esfera.h"
#include <GL/glut.h>
void Esfera::Dibujar()
{
	glutSolidSphere(radio, 32, 32);
}
