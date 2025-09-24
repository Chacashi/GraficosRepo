#include "Light.h"

void Light::sendColor4f(GLenum pname, GLenum lightId, const Color& c)
{
	GLfloat v[4] = { c.r, c.g, c.b, c.a };
	glLightfv(lightId, pname, v);
}

Light::Light()
{
}

void Light::enable()
{
	enabled = true; glEnable(glld);
}

void Light::disable()
{
	enabled = false; glDisable(glld);
}
void Light::setEnabled(bool value)
{
	if (value)
		enable();
	else
		disable();
}
void Light::setAmbient(const Color& c)
{
	ambient = c;
}

void Light::setDiffuse(const Color& c)
{
	diffuse = c;
}

void Light::setSpecular(const Color& c)
{
	specular = c;
}

void Light::applyCommonColors()
{
	sendColor4f(GL_AMBIENT, glld, ambient);
	sendColor4f(GL_DIFFUSE, glld, diffuse);
	sendColor4f(GL_SPECULAR, glld, specular);
}

GLenum Light::id() const
{
	return glld;
}
