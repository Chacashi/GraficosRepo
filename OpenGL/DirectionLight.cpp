#include "DirectionLight.h"
#include "SpotLigth.h"

DirectionLight::DirectionLight(GLenum lightd): Light(lightd)
{
}

void DirectionLight::setDirection(const Vector3D& dir)
{
    direction = dir;
	if (direction.lenght() > 0) direction.normalized();
	else direction = Vector3D(0, -1, 0);
}


Vector3D DirectionLight::getDirection() const
{
    return direction;
}

void DirectionLight::apply()
{
    if (!enabled) return;
    applyCommonColors();
    GLfloat pos[4] = { -direction.x, -direction.y, -direction.z, 0.0f };
    glLightfv(glld, GL_POSITION, pos);
}
