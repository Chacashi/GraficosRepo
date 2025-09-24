#pragma once
#include "Light.h"
#include "Vector3D.h"
class PointLight :
    public Light
{
public:
	Vector3D position{ 0,0,0 };
	float constantAtt = 1.0f;
	float linearAtt = 0.0f;
	float quadraticAtt = 0.0f;

	PointLight(GLenum lightId);

	void setPosition(const Vector3D& p);
	void setAttenuation(float kc, float kl, float kq);
	Vector3D getPosition() const;

	void apply() override;



};
