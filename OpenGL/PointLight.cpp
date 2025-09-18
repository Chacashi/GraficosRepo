#include "PointLight.h"



PointLight::PointLight(GLenum lightId) : Light(lightId), constantAtt(1.0f), linearAtt(0.0f), quadraticAtt(0.0f) {}

void PointLight::setPosition(const Vector3D& p) 
{ 
	position = p; 
}

void PointLight::setAttenuation(float kc, float kl, float kq) {
    constantAtt = (kc < 0.f ? 0.f : kc);
    linearAtt = (kl < 0.f ? 0.f : kl);
    quadraticAtt = (kq < 0.f ? 0.f : kq);
}

Vector3D PointLight::getPosition() const 
{
    return position; 
}

void PointLight::apply()
{
    if (!enabled) return;
    applyCommonColors();

    GLfloat posv[4] = { position.x, position.y, position.z, 1.0f };
    glLightfv(glld, GL_POSITION, posv);

    glLightf(glld, GL_CONSTANT_ATTENUATION, constantAtt);
    glLightf(glld, GL_LINEAR_ATTENUATION, linearAtt);
    glLightf(glld, GL_QUADRATIC_ATTENUATION, quadraticAtt);

}
