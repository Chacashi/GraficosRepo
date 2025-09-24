#pragma once
#include "Light.h"
#include "Vector3D.h"
class DirectionLight :
    public Light
{
    Vector3D direction{ 0,-1,0 };
public:
    DirectionLight(GLenum lightd);
	void setDirection(const Vector3D& dir);
	Vector3D getDirection() const;

    void apply() override;

};

