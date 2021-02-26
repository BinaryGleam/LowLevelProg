#pragma once
#include <iostream>

namespace Mmath
{
	struct AVector2
	{
		/* Variables */
		float x = 0.0f, y = 0.0f;


		/* Static variables */
		static AVector2 Zero();
		static AVector2 One();
		static AVector2 Up();
		static AVector2 Down();
		static AVector2 Right();
		static AVector2 Left();


		/* Constructors */
		AVector2(const float _x = 0.0f, const float _y = 0.0f);
		AVector2(const AVector2& _vec2);


		/* Destructors */
		~AVector2() = default;


		/* Methods */
		void Normalize();
		float DotProduct(const AVector2& _rhs) const;
		static float DotProduct(const AVector2& _lhs, const AVector2& _rhs);
		static AVector2 Lerp(const AVector2& _from, const AVector2& _to, float _speed);
		static float Angle(AVector2 _a, AVector2 _b);
		static AVector2 Max(AVector2 _a, AVector2 _b);
		static AVector2 Min(AVector2 _a, AVector2 _b);
		static AVector2 MoveTowards(AVector2 _current, AVector2 _target, float _speed);


		/* Getters */
		static float GetDistance(const AVector2& _first, const AVector2& _second);
		float GetDistance(const AVector2& _vec2) const;
		float GetMagnitude() const;
		float GetSquareMagnitude() const;
		AVector2 GetNormalized() const;


		/* Operators */
		AVector2 operator-();
		float operator,(const AVector2& _otherVector) const;	//DotProduct
		AVector2 operator*(const AVector2& _otherVector) const;
		AVector2 operator*(float _value) const;
		void operator*=(const AVector2& _otherVector);
		AVector2 operator/(float _value) const;
		AVector2 operator+(const AVector2& _otherVector) const;
		void operator+=(const AVector2& _otherVector);
		AVector2 operator-(const AVector2& _otherVector) const;
		void operator-=(const AVector2& _otherVector);

		void operator=(const AVector2& _otherVector);
		bool operator==(const AVector2& _otherVector) const;
		bool operator!=(const AVector2& _otherVector) const;
		bool operator<(const AVector2& _otherVector) const;
		bool operator>(const AVector2& _otherVector) const;
		bool operator<=(const AVector2& _otherVector) const;
		bool operator>=(const AVector2& _otherVector) const;
	};

	/* External Operators */
	AVector2 operator*(float _f, const AVector2& _vector);
	AVector2& operator*(float _f, AVector2& _vector);
	AVector2 operator/(float _f, const AVector2& _vector);
	AVector2& operator/(float _f, AVector2& _vector);
	std::string& operator+(std::string& _string, const AVector2& _vector);
	std::string& operator+=(std::string& _string, const AVector2& _vector);
	std::ostream& operator<<(std::ostream& _outStream, const AVector2& _vector);
	std::istream& operator>>(std::istream& _inStream, AVector2& _vector);
}