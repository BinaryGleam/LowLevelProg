#pragma once

#pragma once
#include <iostream>

#ifndef M_PI
#define M_PI       3.14159265358979323846f
#endif
#ifndef M_RAD
#define M_RAD       M_PI / 180.0f
#endif

#ifndef ToDegrees
#define ToDegrees(X) X*(180/M_PI)
#endif

#ifndef ToRads
#define ToRads(X) X*(M_PI/180)
#endif

namespace Mmath
{
	struct AVector4
	{
		/* Variables */
		float x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f;


		/* Static variables */
		static AVector4 Zero();
		static AVector4 One();
		static AVector4 Up();
		static AVector4 Down();
		static AVector4 Right();
		static AVector4 Left();


		/* Constructors */
		AVector4(const float _x = 0.0f, const float _y = 0.0f, const float _z = 0.0f, const float _w = 0.0f);
		AVector4(const AVector4& _vec2);


		/* Destructors */
		~AVector4() = default;


		/* Methods */
		void Normalize();
		float DotProduct(const AVector4& _rhs) const;
		static float DotProduct(const AVector4& _lhs, const AVector4& _rhs);
		static AVector4 Lerp(const AVector4& _from, const AVector4& _to, float _speed);
		static float Angle(AVector4 _a, AVector4 _b);

		/* Getters */
		static float GetDistance(const AVector4& _first, const AVector4& _second);
		float GetDistance(const AVector4& _vec2) const;
		float GetMagnitude() const;
		float GetSquareMagnitude() const;
		AVector4 GetNormalized() const;


		/* Operators */
		AVector4 operator-();
		float operator,(const AVector4& _otherVector) const;	//DotProduct
		AVector4 operator*(const AVector4& _otherVector) const;
		AVector4 operator*(float _value) const;
		void operator*=(const AVector4& _otherVector);
		AVector4 operator/(float _value) const;
		AVector4 operator+(const AVector4& _otherVector) const;
		void operator+=(const AVector4& _otherVector);
		AVector4 operator-(const AVector4& _otherVector) const;
		void operator-=(const AVector4& _otherVector);

		void operator=(const AVector4& _otherVector);
		bool operator==(const AVector4& _otherVector) const;
		bool operator!=(const AVector4& _otherVector) const;
		bool operator<(const AVector4& _otherVector) const;
		bool operator>(const AVector4& _otherVector) const;
		bool operator<=(const AVector4& _otherVector) const;
		bool operator>=(const AVector4& _otherVector) const;
	};

	/* External Operators */
	AVector4 operator*(float _f, const AVector4& _vector);
	AVector4& operator*(float _f, AVector4& _vector);
	AVector4 operator/(float _f, const AVector4& _vector);
	AVector4& operator/(float _f, AVector4& _vector);
	std::string& operator+(std::string& _string, const AVector4& _vector);
	std::string& operator+=(std::string& _string, const AVector4& _vector);
	std::ostream& operator<<(std::ostream& _outStream, const AVector4& _vector);
	std::istream& operator>>(std::istream& _inStream, AVector4& _vector);
}