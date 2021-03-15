#ifndef __VECTOR4_H__
#define __VECTOR4_H__

#include "Vector3.h"

namespace CMath
{
	struct Vector4
	{
		/* Variables */

		float s_x = 0.0f, s_y = 0.0f, s_z = 0.0f, s_w = 1.0f;

		/* Static variables */

		static Vector4 Zero();
		static Vector4 One();

		/* Constructors */

		Vector4(const float _x = 0.0f, const float _y = 0.0f, const float _z = 0.0f, const float _w = 1.0f);
		Vector4(const Vector4& _vec4);
		Vector4(const Vector3& _vec3, const float _w = 1.0f);

		/* Destructor */

		~Vector4() = default;

		/* Methods */

		void Homogenize();
		void Normalize();
		float DotProduct(const Vector4& _rhs) const;
		static float DotProduct(const Vector4& _lhs, const Vector4& _rhs);
		static Vector4 Lerp(const Vector4& _from, const Vector4& _to, float _speed);
		static Vector4 MoveTowards(Vector4 _current, Vector4 _target, float _speed);

		/* Getters */
		static float GetDistance2D(const Vector4& _first, const Vector4& _second);
		static float GetDistance(const Vector4& _first, const Vector4& _second);
		float GetDistance2D(const Vector4& _vec4) const;
		float GetDistance(const Vector4& _vec4) const;
		float GetMagnitude() const;
		float GetSquareMagnitude() const;
		Vector4 GetNormalized() const;

		/* Operators */

		Vector4 operator-() const;
		float operator,(const Vector4& _otherVector) const;	//DotProduct
		Vector4 operator*(const Vector4& _otherVector) const;
		Vector4 operator*(float _value) const;
		void operator*=(const Vector4& _otherVector);
		Vector4 operator/(float _value) const;
		Vector4 operator+(const Vector4& _otherVector) const;
		Vector4 operator+(const Vector3& _otherVector) const;
		void operator+=(const Vector4& _otherVector);
		void operator+=(const Vector3& _otherVector);
		Vector4 operator-(const Vector4& _otherVector) const;
		Vector4 operator-(const Vector3& _otherVector) const;
		void operator-=(const Vector4& _otherVector);
		void operator-=(const Vector3& _otherVector);

		void operator=(const Vector4& _otherVector);
		bool operator==(const Vector4& _otherVector) const;
		bool operator!=(const Vector4& _otherVector) const;
		bool operator<(const Vector4& _otherVector) const;
		bool operator>(const Vector4& _otherVector) const;
		bool operator<=(const Vector4& _otherVector) const;
		bool operator>=(const Vector4& _otherVector) const;
	};

	/* External Operators */

	Vector4 operator*(float _f, const Vector4& _vector);
	Vector4& operator*(float _f, Vector4& _vector);
	Vector4 operator/(float _f, const Vector4& _vector);
	Vector4& operator/(float _f, Vector4& _vector);
	Vector4 operator+(Vector3 _vec3, const Vector4& _vec4);
	Vector4& operator+(Vector3 _vec3, Vector4& _vec4);
	Vector4 operator-(Vector3 _vec3, const Vector4& _vec4);
	Vector4& operator-(Vector3 _vec3, Vector4& _vec4);
	std::string& operator+(std::string& _string, const Vector4& _vector);
	std::string& operator+=(std::string& _string, const Vector4& _vector);
	std::ostream& operator<<(std::ostream& _outStream, const Vector4& _vector);
}

#endif