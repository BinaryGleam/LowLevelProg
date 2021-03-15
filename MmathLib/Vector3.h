#ifndef __VECTOR3_H__
#define __VECTOR3_H__

#include "Vector2.h"

namespace CMath
{
	struct Vector3
	{
		/* Variables */

		float s_x = 0.0f, s_y = 0.0f, s_z = 0.0f;

		/* Static variables */

		static Vector3 Zero();
		static Vector3 One();
		static Vector3 Up();
		static Vector3 Down();
		static Vector3 Right();
		static Vector3 Left();
		static Vector3 Forward();
		static Vector3 Back();

		/* Constructors */

		Vector3(const float _x = 0.0f, const float _y = 0.0f, const float _z = 0.0f);
		Vector3(const Vector3& _vec3);
		Vector3(const Vector2& _vec2, const float _z = 0.0f);

		/* Destructor */

		~Vector3() = default;

		/* Methods */

		void Normalize();
		static Vector3 Normalize(Vector3 _vector);
		Vector3 CrossProduct(const Vector3& _otherVector) const;
		static Vector3 CrossProduct(const Vector3& _firstVector, const Vector3& _secondVector);
		float DotProduct(const Vector3& _rhs) const;
		static float DotProduct(const Vector3& _lhs, const Vector3& _rhs);
		static Vector3 Lerp(const Vector3& _from, const Vector3& _to, float _speed);
		static float Angle(Vector3 _a, Vector3 _b);
		static Vector3 Max(Vector3 _a, Vector3 _b);
		static Vector3 Min(Vector3 _a, Vector3 _b);
		static Vector3 MoveTowards(Vector3 _current, Vector3 _target, float _speed);

		/* Getters */

		static float GetDistance2D(const Vector3& _first, const Vector3& _second);
		static float GetDistance(const Vector3& _first, const Vector3& _second);
		float GetDistance2D(const Vector3& _vec3) const;
		float GetDistance(const Vector3& _vec3) const;
		float GetMagnitude() const;
		float GetSquareMagnitude() const;
		Vector3 GetNormalized() const;

		/* Operators */

		Vector3 operator-() const;
		float operator,(const Vector3& _otherVector) const;	//DotProduct
		Vector3 operator*(const Vector3& _otherVector) const;
		Vector3 operator*(float _value) const;
		void operator*=(const Vector3& _otherVector);
		Vector3 operator/(const Vector3& _otherVector) const;
		Vector3 operator/(float _value) const;
		Vector3 operator+(const Vector3& _otherVector) const;
		Vector3 operator+(const Vector2& _otherVector) const;
		void operator+=(const Vector3& _otherVector);
		void operator+=(const Vector2& _otherVector);
		Vector3 operator-(const Vector3& _otherVector) const;
		Vector3 operator-(const Vector2& _otherVector) const;
		void operator-=(const Vector3& _otherVector);
		void operator-=(const Vector2& _otherVector);

		void operator=(const Vector3& _otherVector);
		bool operator==(const Vector3& _otherVector) const;
		bool operator!=(const Vector3& _otherVector) const;
		bool operator<(const Vector3& _otherVector) const;
		bool operator>(const Vector3& _otherVector) const;
		bool operator<=(const Vector3& _otherVector) const;
		bool operator>=(const Vector3& _otherVector) const;
	};

	/* External Operators */

	Vector3 operator*(float _f, const Vector3& _vector);
	Vector3& operator*(float _f, Vector3& _vector);
	Vector3 operator/(float _f, const Vector3& _vector);
	Vector3& operator/(float _f, Vector3& _vector);
	Vector3 operator+(Vector2 _vec2, const Vector3& _vec3);
	Vector3& operator+(Vector2 _vec2, Vector3& _vec3);
	Vector3 operator-(Vector2 _vec2, const Vector3& _vec3);
	Vector3& operator-(Vector2 _vec2, Vector3& _vec3);
	std::string& operator+(std::string& _string, const Vector3& _vector);
	std::string& operator+=(std::string& _string, const Vector3& _vector);
	std::ostream& operator<<(std::ostream& _outStream, const Vector3& _vector);
	std::istream& operator>>(std::istream& _inStream, Vector3& _vector);
}
#endif