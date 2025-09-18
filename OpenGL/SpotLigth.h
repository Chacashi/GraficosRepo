#pragma once
#include "Light.h"
#include "Vector3D.h"
class SpotLigth :
    public Light
{
public:
    Vector3D position;
	Vector3D direction;
	float cutoffAngle;

	void apply() override;

	

};

