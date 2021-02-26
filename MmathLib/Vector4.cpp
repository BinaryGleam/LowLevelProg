#include "Vector4.h"

namespace CMath
{
	/* Static variables */

	Vector4 Vector4::Zero()
	{
		return Vector4(0.0f, 0.0f, 0.0f, 0.0f);
	}
	Vector4 Vector4::One()
	{
		return Vector4(1.0f, 1.0f, 1.0f, 1.0f);
	}


	/* Constructors */

	Vector4::Vector4(const float _x, const float _y, const float _z, const float _w)
		: s_x{ _x }, s_y{ _y }, s_z{ _z }, s_w{ _w }
	{}

	Vector4::Vector4(const Vector4& _vec4)
		: s_x{ _vec4.s_x }, s_y{ _vec4.s_y }, s_z{ _vec4.s_z }, s_w{ _vec4.s_w }
	{}

	Vector4::Vector4(const Vector3& _vec3, const float _w)
		: s_x{ _vec3.s_x }, s_y{ _vec3.s_y }, s_z{ _vec3.s_z }, s_w{ _w }
	{}


	/* Methods */

	void Vector4::Homogenize()
	{
		if (s_w != 0)
		{
			s_x /= s_w;
			s_y /= s_w;
			s_z /= s_w;
		}
	}
	void Vector4::Normalize()
	{
		float length = GetMagnitude();
		if (length != 0)
		{
			s_x /= length;
			s_y /= length;
			s_z /= length;
			s_w /= length;
		}
	}
	float Vector4::DotProduct(const Vector4& _rhs) const
	{
		return ((s_x*_rhs.s_x) + (s_y*_rhs.s_y) + (s_z*_rhs.s_z));
	}
	float Vector4::DotProduct(const Vector4& _lhs, const Vector4& _rhs)
	{
		return ((_lhs.s_x*_rhs.s_x) + (_lhs.s_y*_rhs.s_y) + (_lhs.s_z*_rhs.s_z));
	}
	Vector4 Vector4::Lerp(const Vector4& _from, const Vector4& _to, float _speed)
	{
		return (1 - _speed) * _from + _to * _speed;
	}
	Vector4 Vector4::MoveTowards(Vector4 _current, Vector4 _target, float _speed)
	{
		Vector4 temp = _target - _current;
		float magnitude = temp.GetMagnitude();

		if (magnitude <= _speed || magnitude == 0.f)
			return _target;

		return _current + temp / magnitude * _speed;
	}


	/* Getters */
	float Vector4::GetDistance2D(const Vector4& _first, const Vector4& _second)
	{
		return sqrtf((_first.s_x - _second.s_x)*(_first.s_x - _second.s_x)
			+ (_first.s_y - _second.s_y)*(_first.s_y - _second.s_y));
	}
	float Vector4::GetDistance(const Vector4& _first, const Vector4& _second)
	{
		return sqrtf((_first.s_x - _second.s_x)*(_first.s_x - _second.s_x)
			+ (_first.s_y - _second.s_y)*(_first.s_y - _second.s_y)
			+ (_first.s_z - _second.s_z)*(_first.s_z - _second.s_z)
			+ (_first.s_w - _second.s_w)*(_first.s_w - _second.s_w));
	}
	float Vector4::GetDistance2D(const Vector4& _vec3) const
	{
		return sqrtf((s_x - _vec3.s_x)*(s_x - _vec3.s_x)
			+ (s_y - _vec3.s_y)*(s_y - _vec3.s_y));
	}
	float Vector4::GetDistance(const Vector4& _vec3) const
	{
		return sqrtf((s_x - _vec3.s_x)*(s_x - _vec3.s_x)
			+ (s_y - _vec3.s_y)*(s_y - _vec3.s_y)
			+ (s_z - _vec3.s_z)*(s_z - _vec3.s_z)
			+ (s_w - _vec3.s_w)*(s_w - _vec3.s_w));
	}
	float Vector4::GetMagnitude() const
	{
		return sqrtf(s_x*s_x + s_y*s_y + s_z*s_z + s_w*s_w);
	}
	float Vector4::GetSquareMagnitude() const
	{
		return s_x*s_x + s_y*s_y + s_z*s_z + s_w*s_w;
	}
	Vector4 Vector4::GetNormalized() const
	{
		float length = GetMagnitude();

		return Vector4(s_x / length, s_y / length, s_z / length, s_w / length);
	}


	/* Operators */
	Vector4 Vector4::operator-() const
	{
		return Vector4(-s_x, -s_y, -s_z, -s_w);
	}
	float Vector4::operator,(const Vector4& _otherVector) const
	{
		return DotProduct(_otherVector);
	}
	Vector4 Vector4::operator*(const Vector4& _otherVector) const
	{
		return Vector4(s_x * _otherVector.s_x, s_y * _otherVector.s_y, s_z * _otherVector.s_z, s_w * _otherVector.s_w);
	}
	Vector4 Vector4::operator*(float _value) const
	{
		return Vector4(s_x * _value, s_y * _value, s_z * _value, s_w * _value);
	}
	void Vector4::operator*=(const Vector4& _otherVector)
	{
		Vector4 vec(s_x * _otherVector.s_x, s_y * _otherVector.s_y, s_z * _otherVector.s_z, s_w * _otherVector.s_w);
		s_x = vec.s_x;
		s_y = vec.s_y;
		s_z = vec.s_z;
		s_w = vec.s_w;
	}
	Vector4 Vector4::operator/(float _value) const
	{
		return Vector4(s_x / _value, s_y / _value, s_z / _value, s_w / _value);
	}
	Vector4 Vector4::operator+(const Vector4& _otherVector) const
	{
		return Vector4(s_x + _otherVector.s_x, s_y + _otherVector.s_y, s_z + _otherVector.s_z, s_w + _otherVector.s_w);
	}
	Vector4 Vector4::operator+(const Vector3& _otherVector) const
	{
		return Vector4(s_x + _otherVector.s_x, s_y + _otherVector.s_y, s_z + _otherVector.s_z, s_w);
	}
	void Vector4::operator+=(const Vector4& _otherVector)
	{
		s_x += _otherVector.s_x;
		s_y += _otherVector.s_y;
		s_z += _otherVector.s_z;
		s_w += _otherVector.s_w;
	}
	void Vector4::operator+=(const Vector3& _otherVector)
	{
		s_x += _otherVector.s_x;
		s_y += _otherVector.s_y;
		s_z += _otherVector.s_z;
	}
	Vector4 Vector4::operator-(const Vector4& _otherVector) const
	{
		return Vector4(s_x - _otherVector.s_x, s_y - _otherVector.s_y, s_z - _otherVector.s_z, s_w - _otherVector.s_w);
	}
	Vector4 Vector4::operator-(const Vector3& _otherVector) const
	{
		return Vector4(s_x - _otherVector.s_x, s_y - _otherVector.s_y, s_z - _otherVector.s_z, s_w);
	}
	void Vector4::operator-=(const Vector4& _otherVector)
	{
		s_x -= _otherVector.s_x;
		s_y -= _otherVector.s_y;
		s_z -= _otherVector.s_z;
		s_w -= _otherVector.s_w;
	}
	void Vector4::operator-=(const Vector3& _otherVector)
	{
		s_x -= _otherVector.s_x;
		s_y -= _otherVector.s_y;
		s_z -= _otherVector.s_z;
	}

	void Vector4::operator=(const Vector4& _otherVector)
	{
		s_x = _otherVector.s_x;
		s_y = _otherVector.s_y;
		s_z = _otherVector.s_z;
		s_w = _otherVector.s_w;
	}
	bool Vector4::operator==(const Vector4& _otherVector) const
	{
		if (s_x == _otherVector.s_x && s_y == _otherVector.s_y && s_z == _otherVector.s_z && s_w == _otherVector.s_w)
			return true;
		else
			return false;
	}
	bool Vector4::operator!=(const Vector4& _otherVector) const
	{
		if (s_x == _otherVector.s_x && s_y == _otherVector.s_y && s_z == _otherVector.s_z && s_w == _otherVector.s_w)
			return false;
		else
			return true;
	}
	bool Vector4::operator<(const Vector4& _otherVector) const
	{
		if (GetMagnitude() < _otherVector.GetMagnitude())
			return true;
		else
			return false;
	}
	bool Vector4::operator>(const Vector4& _otherVector) const
	{
		if (GetMagnitude() > _otherVector.GetMagnitude())
			return true;
		else
			return false;
	}
	bool Vector4::operator<=(const Vector4& _otherVector) const
	{
		if (GetMagnitude() <= _otherVector.GetMagnitude())
			return true;
		else
			return false;
	}
	bool Vector4::operator>=(const Vector4& _otherVector) const
	{
		if (GetMagnitude() >= _otherVector.GetMagnitude())
			return true;
		else
			return false;
	}


	/* External Operators */

	Vector4 operator*(float _f, const Vector4& _vector)
	{
		return Vector4(_vector.s_x*_f, _vector.s_y*_f, _vector.s_z*_f, _vector.s_w*_f);
	}
	Vector4& operator*(float _f, Vector4& _vector)
	{
		_vector.s_x *= _f;
		_vector.s_y *= _f;
		_vector.s_z *= _f;
		_vector.s_w *= _f;

		return _vector;
	}
	Vector4 operator/(float _f, const Vector4& _vector)
	{
		Vector4 temp;
		if (_vector.s_x != 0)
			temp.s_x = _f / _vector.s_x;
		if (_vector.s_y != 0)
			temp.s_y = _f / _vector.s_y;
		if (_vector.s_z != 0)
			temp.s_z = _f / _vector.s_z;
		if (_vector.s_w != 0)
			temp.s_w = _f / _vector.s_w;

		return temp;
	}
	Vector4 operator+(Vector3 _vec3, const Vector4& _vec4)
	{
		return Vector4(_vec4.s_x + _vec3.s_x, _vec4.s_y + _vec3.s_y, _vec4.s_z + _vec3.s_z, _vec4.s_w);
	}
	Vector4& operator+(Vector3 _vec3, Vector4& _vec4)
	{
		_vec4.s_x += _vec3.s_x;
		_vec4.s_y += _vec3.s_y;
		_vec4.s_z += _vec3.s_z;

		return _vec4;
	}
	Vector4 operator-(Vector3 _vec3, const Vector4& _vec4)
	{
		return Vector4(_vec3.s_x - _vec4.s_x, _vec3.s_y - _vec4.s_y, _vec3.s_z - _vec4.s_z, 1.0f - _vec4.s_w);
	}
	Vector4& operator-(Vector3 _vec3, Vector4& _vec4)
	{
		Vector4 temp(_vec3);

		temp.s_x -= _vec4.s_x;
		temp.s_y -= _vec4.s_y;
		temp.s_z -= _vec4.s_z;
		temp.s_w -= _vec4.s_w;

		return temp;
	}
	std::string& operator+(std::string& _string, const Vector4& _vector)
	{
		_string = "Vec4(";
		_string += std::to_string(_vector.s_x);
		_string += ", ";
		_string += std::to_string(_vector.s_y);
		_string += ", ";
		_string += std::to_string(_vector.s_z);
		_string += ", ";
		_string += std::to_string(_vector.s_w);
		_string += ")\n";
		return _string;
	}
	std::string& operator+=(std::string& _string, const Vector4& _vector)
	{
		_string += "Vec4(";
		_string += std::to_string(_vector.s_x);
		_string += ", ";
		_string += std::to_string(_vector.s_y);
		_string += ", ";
		_string += std::to_string(_vector.s_z);
		_string += ", ";
		_string += std::to_string(_vector.s_w);
		_string += ")\n";
		return _string;
	}

	std::ostream& operator<<(std::ostream& _outStream, const Vector4& _vector)
	{
		return _outStream << "Vec4(" << _vector.s_x << ", " << _vector.s_y << ", " << _vector.s_z << ", " << _vector.s_w << ")\n";
	}
}