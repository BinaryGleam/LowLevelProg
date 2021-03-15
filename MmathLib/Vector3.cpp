#include "Vector3.h"

namespace CMath
{
	/* Static variables */

	Vector3 Vector3::Zero()
	{
		return Vector3(0.0f, 0.0f, 0.0f);
	}
	Vector3 Vector3::One()
	{
		return Vector3(1.0f, 1.0f, 1.0f);
	}
	Vector3 Vector3::Up()
	{
		return Vector3(0.0f, 1.0f, 0.0f);
	}
	Vector3 Vector3::Down()
	{
		return Vector3(0.0f, -1.0f, 0.0f);
	}
	Vector3 Vector3::Right()
	{
		return Vector3(1.0f, 0.0f, 0.0f);
	}
	Vector3 Vector3::Left()
	{
		return Vector3(-1.0f, 0.0f, 0.0f);
	}
	Vector3 Vector3::Forward()
	{
		return Vector3(0.0f, 0.0f, 1.0f);
	}
	Vector3 Vector3::Back()
	{
		return Vector3(0.0f, 0.0f, -1.0f);
	}

	/* Constructors */

	Vector3::Vector3(const float _x, const float _y, const float _z)
		: s_x{ _x }, s_y{ _y }, s_z{ _z }
	{}

	Vector3::Vector3(const Vector3& _vec3)
		: s_x{ _vec3.s_x }, s_y{ _vec3.s_y }, s_z{ _vec3.s_z }
	{}

	Vector3::Vector3(const Vector2& _vec2, const float _z)
		: s_x{ _vec2.x }, s_y{ _vec2.y }, s_z{ _z }
	{}

	/* Methods */

	void Vector3::Normalize()
	{
		float length = GetMagnitude();
		if (length != 0)
		{
			s_x /= length;
			s_y /= length;
			s_z /= length;
		}
	}
	Vector3 Vector3::Normalize(Vector3 _vector)
	{
		Vector3 v = _vector;

		float length = v.GetMagnitude();
		if (length != 0)
		{
			v.s_x /= length;
			v.s_y /= length;
			v.s_z /= length;
		}

		return v;
	}
	Vector3 Vector3::CrossProduct(const Vector3& _otherVector) const
	{
		float a = s_y * _otherVector.s_z - s_z * _otherVector.s_y;
		float b = s_z * _otherVector.s_x - s_x * _otherVector.s_z;
		float c = s_x * _otherVector.s_y - s_y * _otherVector.s_x;

		return Vector3(a, b, c);
	}
	Vector3 Vector3::CrossProduct(const Vector3& _firstVector, const Vector3& _secondVector)
	{
		float a = _firstVector.s_y * _secondVector.s_z - _firstVector.s_z * _secondVector.s_y;
		float b = _firstVector.s_z * _secondVector.s_x - _firstVector.s_x * _secondVector.s_z;
		float c = _firstVector.s_x * _secondVector.s_y - _firstVector.s_y * _secondVector.s_x;

		return Vector3(a, b, c);
	}
	float Vector3::DotProduct(const Vector3& _rhs) const
	{
		return ((s_x * _rhs.s_x) + (s_y * _rhs.s_y) + (s_z * _rhs.s_z));
	}
	float Vector3::DotProduct(const Vector3& _lhs, const Vector3& _rhs)
	{
		return ((_lhs.s_x * _rhs.s_x) + (_lhs.s_y * _rhs.s_y) + (_lhs.s_z * _rhs.s_z));
	}
	Vector3 Vector3::Lerp(const Vector3& _from, const Vector3& _to, float _speed)
	{
		return (1 - _speed) * _from + _to * _speed;
	}
	float Vector3::Angle(Vector3 _a, Vector3 _b)
	{
		return ToDegrees(acos(Vector3::DotProduct(_a, _b) / (_a.GetMagnitude() * _b.GetMagnitude())));
	}
	Vector3 Vector3::Max(Vector3 _a, Vector3 _b)
	{
		Vector3 temp;

		if (_a.s_x > _b.s_x)
			temp.s_x = _a.s_x;
		else
			temp.s_x = _b.s_x;

		if (_a.s_y > _b.s_y)
			temp.s_y = _a.s_y;
		else
			temp.s_y = _b.s_y;

		if (_a.s_z > _b.s_z)
			temp.s_z = _a.s_z;
		else
			temp.s_z = _b.s_z;

		return temp;
	}
	Vector3 Vector3::Min(Vector3 _a, Vector3 _b)
	{
		Vector3 temp;

		if (_a.s_x < _b.s_x)
			temp.s_x = _a.s_x;
		else
			temp.s_x = _b.s_x;

		if (_a.s_y < _b.s_y)
			temp.s_y = _a.s_y;
		else
			temp.s_y = _b.s_y;

		if (_a.s_z < _b.s_z)
			temp.s_z = _a.s_z;
		else
			temp.s_z = _b.s_z;

		return temp;
	}
	Vector3 Vector3::MoveTowards(Vector3 _current, Vector3 _target, float _speed)
	{
		Vector3 temp = _target - _current;
		float magnitude = temp.GetMagnitude();

		if (magnitude <= _speed || magnitude == 0.f)
			return _target;

		return _current + temp / magnitude * _speed;
	}

	/* Getters */

	float Vector3::GetDistance2D(const Vector3& _first, const Vector3& _second)
	{
		return sqrtf((_first.s_x - _second.s_x) * (_first.s_x - _second.s_x)
			+ (_first.s_y - _second.s_y) * (_first.s_y - _second.s_y));
	}
	float Vector3::GetDistance(const Vector3& _first, const Vector3& _second)
	{
		return sqrtf((_first.s_x - _second.s_x) * (_first.s_x - _second.s_x)
			+ (_first.s_y - _second.s_y) * (_first.s_y - _second.s_y)
			+ (_first.s_z - _second.s_z) * (_first.s_z - _second.s_z));
	}
	float Vector3::GetDistance2D(const Vector3& _vec3) const
	{
		return sqrtf((s_x - _vec3.s_x) * (s_x - _vec3.s_x)
			+ (s_y - _vec3.s_y) * (s_y - _vec3.s_y));
	}
	float Vector3::GetDistance(const Vector3& _vec3) const
	{
		return sqrtf((s_x - _vec3.s_x) * (s_x - _vec3.s_x)
			+ (s_y - _vec3.s_y) * (s_y - _vec3.s_y)
			+ (s_z - _vec3.s_z) * (s_z - _vec3.s_z));
	}
	float Vector3::GetMagnitude() const
	{
		return sqrtf(s_x * s_x + s_y * s_y + s_z * s_z);
	}
	float Vector3::GetSquareMagnitude() const
	{
		return s_x * s_x + s_y * s_y + s_z * s_z;
	}
	Vector3 Vector3::GetNormalized() const
	{
		float length = GetMagnitude();

		return Vector3(s_x / length, s_y / length, s_z / length);
	}

	/* Operators */

	Vector3 Vector3::operator-() const
	{
		return Vector3(-s_x, -s_y, -s_z);
	}
	float Vector3::operator,(const Vector3& _otherVector) const
	{
		return DotProduct(_otherVector);
	}
	Vector3 Vector3::operator*(const Vector3& _otherVector) const
	{
		return Vector3(s_x * _otherVector.s_x, s_y * _otherVector.s_y, s_z * _otherVector.s_z);
	}
	Vector3 Vector3::operator*(float _value) const
	{
		return Vector3(s_x * _value, s_y * _value, s_z * _value);
	}
	void Vector3::operator*=(const Vector3& _otherVector)
	{
		Vector3 vec = CrossProduct(_otherVector);
		s_x = vec.s_x;
		s_y = vec.s_y;
		s_z = vec.s_z;
	}
	Vector3 Vector3::operator/(const Vector3& _otherVector) const
	{
		Vector3 v3(s_x / _otherVector.s_x, s_y / _otherVector.s_y, s_z / _otherVector.s_z);
		if (_otherVector.s_x == 0)
			v3.s_x = 0;
		if (_otherVector.s_y == 0)
			v3.s_y = 0;
		if (_otherVector.s_z == 0)
			v3.s_z = 0;
		return v3;
	}
	Vector3 Vector3::operator/(float _value) const
	{
		return Vector3(s_x / _value, s_y / _value, s_z / _value);
	}
	Vector3 Vector3::operator+(const Vector3& _otherVector) const
	{
		return Vector3(s_x + _otherVector.s_x, s_y + _otherVector.s_y, s_z + _otherVector.s_z);
	}
	Vector3 Vector3::operator+(const Vector2& _otherVector) const
	{
		return Vector3(s_x + _otherVector.x, s_y + _otherVector.y, s_z);
	}
	void Vector3::operator+=(const Vector3& _otherVector)
	{
		s_x += _otherVector.s_x;
		s_y += _otherVector.s_y;
		s_z += _otherVector.s_z;
	}
	void Vector3::operator+=(const Vector2& _otherVector)
	{
		s_x += _otherVector.x;
		s_y += _otherVector.y;
	}
	Vector3 Vector3::operator-(const Vector3& _otherVector) const
	{
		return Vector3(s_x - _otherVector.s_x, s_y - _otherVector.s_y, s_z - _otherVector.s_z);
	}
	Vector3 Vector3::operator-(const Vector2& _otherVector) const
	{
		return Vector3(s_x - _otherVector.x, s_y - _otherVector.y, s_z);
	}
	void Vector3::operator-=(const Vector3& _otherVector)
	{
		s_x -= _otherVector.s_x;
		s_y -= _otherVector.s_y;
		s_z -= _otherVector.s_z;
	}
	void Vector3::operator-=(const Vector2& _otherVector)
	{
		s_x -= _otherVector.x;
		s_y -= _otherVector.y;
	}

	void Vector3::operator=(const Vector3& _otherVector)
	{
		s_x = _otherVector.s_x;
		s_y = _otherVector.s_y;
		s_z = _otherVector.s_z;
	}
	bool Vector3::operator==(const Vector3& _otherVector) const
	{
		if (s_x == _otherVector.s_x && s_y == _otherVector.s_y && s_z == _otherVector.s_z)
			return true;
		else
			return false;
	}
	bool Vector3::operator!=(const Vector3& _otherVector) const
	{
		if (s_x == _otherVector.s_x && s_y == _otherVector.s_y && s_z == _otherVector.s_z)
			return false;
		else
			return true;
	}
	bool Vector3::operator<(const Vector3& _otherVector) const
	{
		if (GetMagnitude() < _otherVector.GetMagnitude())
			return true;
		else
			return false;
	}
	bool Vector3::operator>(const Vector3& _otherVector) const
	{
		if (GetMagnitude() > _otherVector.GetMagnitude())
			return true;
		else
			return false;
	}
	bool Vector3::operator<=(const Vector3& _otherVector) const
	{
		if (GetMagnitude() <= _otherVector.GetMagnitude())
			return true;
		else
			return false;
	}
	bool Vector3::operator>=(const Vector3& _otherVector) const
	{
		if (GetMagnitude() >= _otherVector.GetMagnitude())
			return true;
		else
			return false;
	}

	/* External Operators */

	Vector3 operator*(float _f, const Vector3& _vector)
	{
		return Vector3(_vector.s_x * _f, _vector.s_y * _f, _vector.s_z * _f);
	}
	Vector3& operator*(float _f, Vector3& _vector)
	{
		_vector.s_x *= _f;
		_vector.s_y *= _f;
		_vector.s_z *= _f;

		return _vector;
	}
	Vector3 operator/(float _f, const Vector3& _vector)
	{
		Vector3 temp;
		if (_vector.s_x != 0)
			temp.s_x = _f / _vector.s_x;
		if (_vector.s_y != 0)
			temp.s_y = _f / _vector.s_y;
		if (_vector.s_z != 0)
			temp.s_z = _f / _vector.s_z;

		return temp;
	}
	Vector3 operator+(Vector2 _vec2, const Vector3& _vec3)
	{
		return Vector3(_vec3.s_x + _vec2.x, _vec3.s_y + _vec2.y, _vec3.s_z);
	}
	Vector3& operator+(Vector2 _vec2, Vector3& _vec3)
	{
		_vec3.s_x += _vec2.x;
		_vec3.s_y += _vec2.y;

		return _vec3;
	}
	Vector3 operator-(Vector2 _vec2, const Vector3& _vec3)
	{
		return Vector3(_vec2.x - _vec3.s_x, _vec2.y - _vec3.s_y, 0.0f - _vec3.s_z);
	}
	Vector3& operator-(Vector2 _vec2, Vector3& _vec3)
	{
		Vector3 temp(_vec2);

		temp.s_x -= _vec3.s_x;
		temp.s_y -= _vec3.s_y;
		temp.s_z -= _vec3.s_z;

		return temp;
	}
	std::string& operator+(std::string& _string, const Vector3& _vector)
	{
		_string = "Vec3(";
		_string += std::to_string(_vector.s_x);
		_string += ", ";
		_string += std::to_string(_vector.s_y);
		_string += ", ";
		_string += std::to_string(_vector.s_z);
		_string += ")\n";
		return _string;
	}
	std::string& operator+=(std::string& _string, const Vector3& _vector)
	{
		_string += "Vec3(";
		_string += std::to_string(_vector.s_x);
		_string += ", ";
		_string += std::to_string(_vector.s_y);
		_string += ", ";
		_string += std::to_string(_vector.s_z);
		_string += ")\n";
		return _string;
	}
	std::ostream& operator<<(std::ostream& _outStream, const Vector3& _vector)
	{
		return _outStream << "Vec3(" << _vector.s_x << ", " << _vector.s_y << ", " << _vector.s_z << ")\n";
	}
	std::istream& operator >> (std::istream& _inStream, Vector3& _vector)
	{
		char c;
		_inStream >> _vector.s_x >> c;

		if (c == ',')
			_inStream >> _vector.s_y;
		else if (c == 'f')
		{
			_inStream >> c;
			if (c == ',')
			{
				_inStream >> _vector.s_y;
				_inStream >> c;
				if (c == ',')
					_inStream >> _vector.s_z;
				else if (c == 'f')
				{
					_inStream >> c;
					if (c == ',')
					{
						_inStream >> _vector.s_z;
					}
				}
			}
			else
				_vector.s_x = _vector.s_y = _vector.s_z = 0.0;
		}
		else
			_vector.s_x = _vector.s_y = _vector.s_z = 0.0;

		return _inStream;
	}
}