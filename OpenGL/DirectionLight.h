#pragma once
#include "Light.h"
#include "Vector3D.h"
class DirectionLight :
    public Light
{

public:
    Vector3D direction;
    DirectionLight(GLenum lightId, const Vector3D& dir = Vector3D(0.0f, -1.0f, 0.0f));

    void apply() override;

};

