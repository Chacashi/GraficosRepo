#pragma once
#include <cmath>
class Vector3D
{

public:
	float x, y, z;


	Vector3D() : x(0), y(0), z(0) {}
	Vector3D(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3D operator +(const Vector3D& v2) const{
		return Vector3D(x + v2.x, y + v2.y, z + v2.z);
	}


	Vector3D operator -(const Vector3D& v2) const {
		return Vector3D(x - v2.x, y - v2.y, z - v2.z);
	}

	Vector3D operator*(float s) const {
		return Vector3D(x * s, y * s, z * s);
	}

	float dot(const Vector3D& v2) const {
		return x * v2.x + y * v2.y + z * v2.z;
	}

	Vector3D cross(const Vector3D& v2) const {
		return Vector3D(
			y * v2.z - z * v2.y,
			z * v2.x - x * v2.z,
			x * v2.y - y * v2.x
		);
	}


	float lenght() const {
		return sqrt(x * x + y * y + z * z);
	}



	Vector3D operator/(float s) const {
		return Vector3D(x / s, y / s, z / s);
	}
	Vector3D normalized() const {
		float mag = lenght();
		return (mag > 0) ? (*this / mag) : Vector3D();
	}


	Vector3D normalWith(const Vector3D& ref) const {
		return this->cross(ref).normalized();
	}


	float angleBetween(const Vector3D& v2) const {
		float mag1 = lenght();
		float mag2 = v2.lenght();
		if (mag1 == 0 || mag2 == 0) return 0.0f;

		float cosTheta = dot(v2) / (mag1 * mag2);

		if (cosTheta > 1.0f) cosTheta = 1.0f;
		if (cosTheta < -1.0f) cosTheta = -1.0f;

		return acos(cosTheta); 
	}


};

