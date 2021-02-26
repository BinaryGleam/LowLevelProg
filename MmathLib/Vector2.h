#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include <iostream>
#include <string>

#define M_PI       3.14159265358979323846f
#define M_RAD       M_PI / 180.0f
#define ToDegrees(X) X*(180/M_PI)
#define ToRads(X) X*(M_PI/180)

namespace CMath
{
	struct Vector2
	{
		/* Variables */

		float x = 0.0f, y = 0.0f;


		/* Static variables */

		static Vector2 Zero();
		static Vector2 One();
		static Vector2 Up();
		static Vector2 Down();
		static Vector2 Right();
		static Vector2 Left();


		/* Constructors */

		Vector2(const float _x = 0.0f, const float _y = 0.0f);
		Vector2(const Vector2& _vec2);


		/* Destructors */

		~Vector2() = default;


		/* Methods */

		void Normalize();
		float DotProduct(const Vector2& _rhs) const;
		static float DotProduct(const Vector2& _lhs, const Vector2& _rhs);
		static Vector2 Lerp(const Vector2& _from, const Vector2& _to, float _speed);
		static float Angle(Vector2 _a, Vector2 _b);
		static Vector2 Max(Vector2 _a, Vector2 _b);
		static Vector2 Min(Vector2 _a, Vector2 _b);
		static Vector2 MoveTowards(Vector2 _current, Vector2 _target, float _speed);


		/* Getters */

		static float GetDistance(const Vector2& _first, const Vector2& _second);
		float GetDistance(const Vector2& _vec2) const;
		float GetMagnitude() const;
		float GetSquareMagnitude() const;
		Vector2 GetNormalized() const;


		/* Operators */

		Vector2 operator-() const;
		float operator,(const Vector2& _otherVector) const;	//DotProduct
		Vector2 operator*(const Vector2& _otherVector) const;
		Vector2 operator*(float _value) const;
		void operator*=(const Vector2& _otherVector);
		Vector2 operator/(float _value) const;
		Vector2 operator+(const Vector2& _otherVector) const;
		void operator+=(const Vector2& _otherVector);
		Vector2 operator-(const Vector2& _otherVector) const;
		void operator-=(const Vector2& _otherVector);

		void operator=(const Vector2& _otherVector);
		bool operator==(const Vector2& _otherVector) const;
		bool operator!=(const Vector2& _otherVector) const;
		bool operator<(const Vector2& _otherVector) const;
		bool operator>(const Vector2& _otherVector) const;
		bool operator<=(const Vector2& _otherVector) const;
		bool operator>=(const Vector2& _otherVector) const;
	};

	/* External Operators */

	Vector2 operator*(float _f, const Vector2& _vector);
	Vector2& operator*(float _f, Vector2& _vector);
	Vector2 operator/(float _f, const Vector2& _vector);
	Vector2& operator/(float _f, Vector2& _vector);
	std::string& operator+(std::string& _string, const Vector2& _vector);
	std::string& operator+=(std::string& _string, const Vector2& _vector);
	std::ostream& operator<<(std::ostream& _outStream, const Vector2& _vector);
	std::istream& operator>>(std::istream& _inStream, Vector2& _vector);
}
#endif