#pragma once
#include "Example.h"
#include "Light.h"
#include "Vector3D.h"
class Example4 :
	public Example
{
	Light* newLight;
	float torusYawDeg = 0.0f;

public:
	Example4();

	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;



	void DrawQuadMinMax(const Vector3D&  min, const Vector3D& max);
	void DrawTorus();
	void DrawTeapot();	

};

