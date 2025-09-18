#pragma once
#include "IncludeGL.h"
#include "Color.h"

class Light
{
public:
	GLenum glld;
	bool enabled{ false };
	Color ambient;
	Color diffuse;
	Color specular;


	Light(int lightID,
		const Color& amb = Color(0.2f, 0.2f, 0.2f, 1.0f),
		const Color& diff = Color(0.5f, 0.5f, 0.5f, 1.0f),
		const Color& spec = Color(1.0f, 1.0f, 1.0f, 1.0f))
	{
		glld = lightID;
		ambient = amb;
		diffuse = diff;
		specular = spec;
	}

	virtual void apply() = 0;

	virtual void enable();
	virtual void disable();

	void setAmbient(const Color& c);
	void setDiffuse(const Color& c);
	void setSpecular(const Color& c);

	void applyCommonColors();

	GLenum id() const;


	static void sendColor4f(GLenum pname, GLenum lightId, const Color& c);


};

