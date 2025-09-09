#pragma once
#include <string>
using namespace std;
class Figura
{
protected:
	string color;
	int grosorBorde;
	int colorA;

public:
	virtual void Dibujar();
};

