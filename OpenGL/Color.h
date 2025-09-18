#pragma once
struct Color
{
	float r, g, b, a;
	Color(float red = 1.0f, float green = 1.0f, float blue = 1.0f, float alpha = 1.0f) {
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}
	Color operator*(float intensity) {
		return Color(r * intensity, g * intensity, b * intensity, a);
	}
};

