#include "SpotLigth.h"


SpotLigth::SpotLigth(GLenum lightd) : Light(lightd)
{
}

void SpotLigth::setPosition(const Vector3D& pos)
{
	position = pos;
}

void SpotLigth::setDirection(const Vector3D& dir)
{
	direction = dir;

	if (direction.lenght() > 0.0f) direction.normalized();
	else direction = Vector3D(0, -1, 0);

	direction = dir.normalized();
}

void SpotLigth::setCutoffAngle(float angle)
{
	if(angle == 180.0f) cutoffAngle = 180.0f;
	else cutoffAngle = clampv(angle, 0.0f, 90.0f);
}


void SpotLigth::setExponent(float exp)
{
	exponent = clampv(exp, 0.0f, 128.0f);
}

void SpotLigth::setAttenuation(float constant, float linear, float quadratic)
{
	constantAttenuation = (constant< 0.f ?0.f:constant);
	linearAttenuation = (linear< 0.f ? 0.f :linear);
	quadraticAttenuation = (quadratic< 0.f ?  0.f : quadratic);
}

Vector3D SpotLigth::getPosition() const
{
	return position;
}

Vector3D SpotLigth::getDirection() const
{
	return direction;
}

float SpotLigth::getCutoffAngle() const
{
	return cutoffAngle;
}
float SpotLigth::getExponent() const
{
	return exponent;
}

void SpotLigth::apply()
{
	if (!enabled) return;
	applyCommonColors();

	GLfloat posv[4] = { position.x, position.y, position.z, 1.0f };
	glLightfv(glld, GL_POSITION, posv);

	GLfloat dirv[3] = { direction.x, direction.y, direction.z };
	glLightfv(glld, GL_SPOT_DIRECTION, dirv);

	glLightf(glld, GL_SPOT_CUTOFF, cutoffAngle);
	glLightf(glld, GL_SPOT_EXPONENT, exponent);

	glLightf(glld, GL_CONSTANT_ATTENUATION, constantAttenuation);
	glLightf(glld, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(glld, GL_QUADRATIC_ATTENUATION, quadraticAttenuation);
}
