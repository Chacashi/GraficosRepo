#pragma once

#include "Transform.h"
using namespace std;
class Figura
{
public:
	Transform transform;
	virtual void Dibujar() = 0;
};

