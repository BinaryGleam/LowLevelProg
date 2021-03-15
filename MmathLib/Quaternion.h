#ifndef __QUATERNION_H__
#define __QUATERNION_H__

#include "Matrix.h"

namespace CMath
{
	struct Quaternion
	{
		/* Variables */

		float  s_w = 1.0f, s_x = 0.0f, s_y = 0.0f, s_z = 0.0f;
		Matrix s_rotationMatrix;

		/* Constructors */

		Quaternion(float _w = 1.0f, float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);
		Quaternion(float _w, const Vector3& _vector);
		Quaternion(const Vector4& _vector);

		/* Destructor */

		~Quaternion() = default;

		/* Methods */

		Quaternion Conjugate() const;
		float DotProduct(const Quaternion& _quaternion) const;
		void Normalize();
		void CreateRotationMatrix();

		/* Statics Methods */

		static Quaternion Identity();
		static Quaternion CreateQuaternionFromAngle(float _angle, Vector3 _rotationAxis);
		static Quaternion Lerp(const Quaternion& _from, const Quaternion& _to, float _speed);
		static Quaternion Slerp(const Quaternion& _from, const Quaternion& _to, float _speed);
		static const Quaternion I(float _rotation = 0);
		static const Quaternion J(float _rotation = 0);
		static const Quaternion K(float _rotation = 0);
		static const Quaternion Euler(Vector3 _eulerAngles);
		static const Quaternion Euler(double _x, double _y, double _z);
		static Quaternion LookRotation(Vector3 _forward, Vector3 _up = Vector3::Up());
		static Quaternion Inverse(Quaternion _quaternion);
		static float Angle(Quaternion _a, Quaternion _b);

		/* Getters */

		float GetReal();
		float GetMagnitude() const;
		float GetSquareMagnitude() const;
		Matrix& GetRotationMatrix();
		Quaternion GetInverse() const;
		Quaternion GetNormalized() const;
		Vector3 GetImaginary();
		Vector3 GetEulerAngles();
		float GetRoll();
		float GetPitch();
		float GetYaw();

		/* Operators */

		void operator*=(const Quaternion& _quaternion);
		void operator+=(const Quaternion& _quaternion);
		void operator-=(const Quaternion& _quaternion);
		Quaternion operator*(const Quaternion& _quaternion);
		Vector3 operator*(const Vector3& _vector) const;
		Quaternion operator*(float _value);
		Quaternion operator*(float _value) const;
		Quaternion operator/(float _value);
		Quaternion operator+(const Quaternion& _quaternion) const;
		Quaternion operator-(const Quaternion& _quaternion) const;
		Quaternion operator-() const;
	};

	/* External Operators */

	Quaternion operator*(float _value, const Quaternion& _quaternion);
	std::ostream& operator<<(std::ostream& _outStream, const Quaternion& _quaternion);
}

#endif