#include "Quaternion.h"

namespace CMath
{
	/* Constructors */

	Quaternion::Quaternion(float _w, float _x, float _y, float _z)
		: s_w{ _w }, s_x{ _x }, s_y{ _y }, s_z{ _z }
	{}
	Quaternion::Quaternion(float _w, const Vector3& _vector)
		: s_w{ _w }, s_x{ _vector.s_x }, s_y{ _vector.s_y }, s_z{ _vector.s_z }
	{}
	Quaternion::Quaternion(const Vector4& _vector)
		: s_w{ _vector.s_w }, s_x{ _vector.s_x }, s_y{ _vector.s_y }, s_z{ _vector.s_z }
	{}


	/* Methods */

	Quaternion Quaternion::Conjugate() const
	{
		return Quaternion(s_w, -s_x, -s_y, -s_z);
	}
	float Quaternion::DotProduct(const Quaternion& _quaternion) const
	{
		return (s_w * _quaternion.s_w) + (s_x * _quaternion.s_x) + (s_y * _quaternion.s_y) + (s_z * _quaternion.s_z);
	}
	void Quaternion::Normalize()
	{
		float length = GetMagnitude();

		s_w /= length;
		s_x /= length;
		s_y /= length;
		s_z /= length;
	}
	void Quaternion::CreateRotationMatrix()
	{
		Normalize();
		s_rotationMatrix =
			Matrix(
				{ 1 + (-2 * ((s_y*s_y) + (s_z*s_z))),	(2 * s_x*s_y) - (2 * s_w*s_z),		(2 * s_x*s_z) + (2 * s_w*s_y),		0,
				(2 * s_x*s_y) + (2 * s_w*s_z),			1 + (-2 * ((s_x*s_x) + (s_z*s_z))),	(2 * s_y*s_z) - (2 * s_w*s_x),		0,
				(2 * s_x*s_z) - (2 * s_w*s_y),			(2 * s_y*s_z) + (2 * s_w*s_x),		1 + (-2 * ((s_x*s_x) + (s_y*s_y))),	0,
				0,										0,									0,									1 });
	}


	/* Statics Methods */

	Quaternion Quaternion::Identity()
	{
		return Quaternion(1, 0, 0, 0);
	}
	Quaternion Quaternion::CreateQuaternionFromAngle(float _angle, Vector3 _rotationAxis)
	{
		const float fHalfAngle = ToRads(_angle) * 0.5f;
		const float fSin = sinf(fHalfAngle);

		_rotationAxis.Normalize();

		Quaternion q;
		q.s_w = cosf(fHalfAngle);
		q.s_x = fSin * _rotationAxis.s_x;
		q.s_y = fSin * _rotationAxis.s_y;
		q.s_z = fSin * _rotationAxis.s_z;

		return q;
	}
	Quaternion Quaternion::Lerp(const Quaternion& _from, const Quaternion& _to, float _speed)
	{
		return (_from*(1 - _speed) + _to * _speed).GetNormalized();
	}
	Quaternion Quaternion::Slerp(const Quaternion& _from, const Quaternion& _to, float _speed)
	{
		Quaternion q;
		float dot = _from.DotProduct(_to);		//dot = cos(theta)

												//If (dot < 0), _from and _to are more than 90 degrees apart, so we can invert one to reduce spinning
		if (dot < 0)
		{
			dot = -dot;
			q = -_to;
		}
		else q = _to;

		if (dot < 0.95f)
		{
			float angle = acosf(dot);
			return (_from*sinf(angle*(1 - _speed)) + q * sinf(angle*_speed)) / sinf(angle);
		}
		else
			return Quaternion().Lerp(_from, q, _speed);	//If the angle is small, use linear interpolation
	}
	const Quaternion Quaternion::I(float _angle)
	{
		return CreateQuaternionFromAngle(_angle, Vector3(1.f, 0.f, 0.f));
	}
	const Quaternion Quaternion::J(float _angle)
	{
		return CreateQuaternionFromAngle(_angle, Vector3(0.f, 1.f, 0.f));
	}
	const Quaternion Quaternion::K(float _angle)
	{
		return CreateQuaternionFromAngle(_angle, Vector3(0.f, 0.f, 1.f));
	}
	const Quaternion Quaternion::Euler(Vector3 _eulerAngles)
	{
		return Euler(_eulerAngles.s_x, _eulerAngles.s_y, _eulerAngles.s_z);
	}
	const Quaternion Quaternion::Euler(double _x, double _y, double _z)
	{
		Quaternion q;

		_x *= ToRads(0.5f);
		_z *= ToRads(0.5f);
		_y *= ToRads(0.5f);

		double c1 = cosf(_x);
		double c2 = cosf(_y);
		double c3 = cosf(_z);

		double s1 = sinf(_x);
		double s2 = sinf(_y);
		double s3 = sinf(_z);

		/*q.s_w = c1*c2*c3 - s1*s2*s3;
		q.s_z = c1*c2*s3 + s1*s2*c3;
		q.s_x = s1*c2*c3 + c1*s2*s3;
		q.s_y = c1*s2*c3 - s1*c2*s3;*/

		q.s_w = c3 * c1 * c2 + s3 * s1 * s2;
		q.s_x = c3 * s1 * c2 - s3 * c1 * s2;
		q.s_y = c3 * c1 * s2 + s3 * s1 * c2;
		q.s_z = s3 * c1 * c2 - c3 * s1 * s2;

		return q;
	}
	Quaternion Quaternion::LookRotation(Vector3 _forward, Vector3 _up)
	{
		Vector3 vector = Vector3::Normalize(_forward);
		Vector3 vector2 = Vector3::Normalize(Vector3::CrossProduct(_up, vector));
		Vector3 vector3 = Vector3::CrossProduct(vector, vector2);

		float temp = (vector2.s_x + vector3.s_y) + vector.s_z;
		Quaternion q;

		if (temp > 0.f)
		{
			float num = sqrt(temp + 1.f);

			q.s_w = num * 0.5f;
			num = 0.5f / num;
			q.s_x = (vector3.s_z - vector.s_y) * num;
			q.s_y = (vector.s_x - vector2.s_z) * num;
			q.s_z = (vector2.s_y - vector3.s_x) * num;

			return q;
		}
		if ((vector2.s_x >= vector3.s_y) && (vector2.s_x >= vector.s_z))
		{
			float num7 = sqrt(((1.f + vector2.s_x) - vector3.s_y) - vector.s_z);
			float num4 = 0.5f / num7;

			q.s_x = 0.5f * num7;
			q.s_y = (vector2.s_y + vector3.s_x) * num4;
			q.s_z = (vector2.s_z + vector.s_x) * num4;
			q.s_w = (vector3.s_z - vector.s_y) * num4;

			return q;
		}
		if (vector3.s_y > vector.s_z)
		{
			float num6 = sqrt(((1.f + vector3.s_y) - vector2.s_x) - vector.s_z);
			float num3 = 0.5f / num6;

			q.s_x = (vector3.s_x + vector2.s_y) * num3;
			q.s_y = 0.5f * num6;
			q.s_z = (vector.s_y + vector3.s_z) * num3;
			q.s_w = (vector.s_x - vector2.s_z) * num3;

			return q;
		}

		float temp2 = sqrt(((1.f + vector.s_z) - vector2.s_x) - vector3.s_y);
		float temp3 = 0.5f / temp2;

		q.s_x = (vector.s_x + vector2.s_z) * temp3;
		q.s_y = (vector.s_y + vector3.s_z) * temp3;
		q.s_z = 0.5f * temp2;
		q.s_w = (vector2.s_y - vector3.s_x) * temp3;

		return q;
	}
	Quaternion Quaternion::Inverse(Quaternion _quaternion)
	{
		float length = _quaternion.GetSquareMagnitude();
		return _quaternion.Conjugate() / length;
	}
	float Quaternion::Angle(Quaternion _a, Quaternion _b)
	{
		Quaternion c = _a * Quaternion::Inverse(_b);
		return ToDegrees(atan2(c.GetImaginary().GetMagnitude(), c.GetReal()) * 2);
	}


	/* Getters */

	float Quaternion::GetReal()
	{
		return s_w;
	}
	float Quaternion::GetMagnitude() const
	{
		return sqrtf((s_w*s_w) + (s_x*s_x) + (s_y*s_y) + (s_z*s_z));
	}
	float Quaternion::GetSquareMagnitude() const
	{
		return (s_w*s_w) + (s_x*s_x) + (s_y*s_y) + (s_z*s_z);
	}
	Matrix& Quaternion::GetRotationMatrix()
	{
		return s_rotationMatrix;
	}
	Quaternion Quaternion::GetInverse() const
	{
		float length = GetSquareMagnitude();
		return Conjugate() / length;
	}
	Quaternion Quaternion::GetNormalized() const
	{
		Quaternion quaternion = *this;
		float length = GetMagnitude();

		quaternion.s_w /= length;
		quaternion.s_x /= length;
		quaternion.s_y /= length;
		quaternion.s_z /= length;

		return quaternion;
	}
	Vector3 Quaternion::GetImaginary()
	{
		return Vector3(s_x, s_y, s_z);
	}
	Vector3 Quaternion::GetEulerAngles()
	{
		Normalize();

		return Vector3(GetRoll(), GetPitch(), GetYaw());
		//return Vector3(GetYaw(), GetPitch(), GetRoll());
		//return Vector3(GetPitch(), GetYaw(), GetRoll());
	}
	float Quaternion::GetRoll()
	{
		double sinr = +2.0 * (s_w * s_x + s_y * s_z);
		double cosr = +1.0 - 2.0 * (s_x * s_x + s_y * s_y);
		return ToDegrees(atan2f(sinr, cosr));
	}
	float Quaternion::GetPitch()
	{
		double sinp = +2.0 * (s_w * s_y - s_z * s_x);
		if (fabs(sinp) >= 1)
			return ToDegrees(copysign(M_PI * 0.5f, sinp)); // use 90 degrees if out of range
		else
			return ToDegrees(asinf(sinp));
	}
	float Quaternion::GetYaw()
	{
		double siny = +2.0 * (s_w * s_z + s_x * s_y);
		double cosy = +1.0 - 2.0 * (s_y * s_y + s_z * s_z);
		return ToDegrees(atan2f(siny, cosy));
	}


	/* Operators */

	void Quaternion::operator*=(const Quaternion& _quaternion)
	{
		Quaternion quaternion = this->operator*(_quaternion);

		s_w = quaternion.s_w;
		s_x = quaternion.s_x;
		s_y = quaternion.s_y;
		s_z = quaternion.s_z;
	}
	void Quaternion::operator+=(const Quaternion& _quaternion)
	{
		s_w += _quaternion.s_w;
		s_x += _quaternion.s_x;
		s_y += _quaternion.s_y;
		s_z += _quaternion.s_z;
	}
	void Quaternion::operator-=(const Quaternion& _quaternion)
	{
		s_w -= _quaternion.s_w;
		s_x -= _quaternion.s_x;
		s_y -= _quaternion.s_y;
		s_z -= _quaternion.s_z;
	}
	Quaternion Quaternion::operator*(const Quaternion& _quaternion)
	{
		Quaternion quaternion;

		quaternion.s_w = (s_w * _quaternion.s_w) - (s_x * _quaternion.s_x) - (s_y * _quaternion.s_y) - (s_z * _quaternion.s_z);

		quaternion.s_x = (s_w * _quaternion.s_x) + (s_x * _quaternion.s_w) + (s_y * _quaternion.s_z) - (s_z * _quaternion.s_y);

		quaternion.s_y = (s_w * _quaternion.s_y) - (s_x * _quaternion.s_z) + (s_y * _quaternion.s_w) + (s_z * _quaternion.s_x);

		quaternion.s_z = (s_w * _quaternion.s_z) + (s_x * _quaternion.s_y) - (s_y * _quaternion.s_x) + (s_z * _quaternion.s_w);

		return quaternion;
	}
	Vector3 Quaternion::operator*(const Vector3& _vector) const
	{
		Quaternion q(*this);
		Vector3 temp;
		temp.s_x = q.s_x; temp.s_y = q.s_y; temp.s_z = q.s_z;
		Vector3 t = 2 * temp.CrossProduct(_vector);
		Vector3 res = _vector + q.s_w * t + temp.CrossProduct(t);
		return res;
	}
	Quaternion Quaternion::operator*(float _value)
	{
		return Quaternion(s_w*_value, s_x*_value, s_y*_value, s_z*_value);
	}
	Quaternion Quaternion::operator*(float _value) const
	{
		return Quaternion(s_w*_value, s_x*_value, s_y*_value, s_z*_value);
	}
	Quaternion Quaternion::operator/(float _value)
	{
		Quaternion quaternion;

		quaternion.s_w = s_w / _value;
		quaternion.s_x = s_x / _value;
		quaternion.s_y = s_y / _value;
		quaternion.s_z = s_z / _value;

		return quaternion;
	}
	Quaternion Quaternion::operator+(const Quaternion& _quaternion) const
	{
		return Quaternion(s_w + _quaternion.s_w, s_x + _quaternion.s_x, s_y + _quaternion.s_y, s_z + _quaternion.s_z);
	}
	Quaternion Quaternion::operator-(const Quaternion& _quaternion) const
	{
		return Quaternion(s_w - _quaternion.s_w, s_x - _quaternion.s_x, s_y - _quaternion.s_y, s_z - _quaternion.s_z);
	}
	Quaternion Quaternion::operator-() const
	{
		return Quaternion{ -s_w, -s_x, -s_y, -s_z };
	}


	/* External Operators */

	Quaternion operator*(float _value, const Quaternion& _quaternion)
	{
		return Quaternion(_quaternion.s_w*_value, _quaternion.s_x*_value, _quaternion.s_y*_value, _quaternion.s_z*_value);
	}
	std::ostream& operator<<(std::ostream& _outStream, const Quaternion& _quaternion)
	{
		return _outStream << "Quaternion(" << _quaternion.s_w << ", " << _quaternion.s_x << ", " << _quaternion.s_y << ", " << _quaternion.s_z << ")\n";
	}
}