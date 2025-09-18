#pragma once
#include "Light.h"
#include "Vector3D.h"
class PointLight :
    public Light
{
public:
	Vector3D position;
	float constantAtt;
	float linearAtt;
	float quadraticAtt;

	PointLight(GLenum lightId);

	void setPosition(const Vector3D& p);
	void setAttenuation(float kc, float kl, float kq);
	Vector3D getPosition() const;

	void apply() override;



};
