#pragma once
#include "Light.h"
#include "Vector3D.h"
class SpotLigth :
    public Light
{
public:
	Vector3D position{ 0,0,0 };
	Vector3D direction{ 0,-1,0 };
	float cutoffAngle= 30.0f;
	float exponent = 16.0f;

	float constantAttenuation = 1.0f;
	float linearAttenuation = 0.0f;
	float quadraticAttenuation = 0.0f;

	SpotLigth(GLenum lightd);

	void setPosition(const Vector3D& pos);
	void setDirection(const Vector3D& dir);
	void setCutoffAngle(float angle);	
	void setExponent(float exp);
	void setAttenuation(float constant, float linear, float quadratic);

	Vector3D getPosition() const;
	Vector3D getDirection() const;
	float getCutoffAngle() const;
	float getExponent() const;

	void apply() override;

	

};

