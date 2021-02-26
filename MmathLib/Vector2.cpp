#include "Vector2.h"

namespace CMath
{
	/* Static variables */

	Vector2 Vector2::Zero()
	{
		return Vector2(0.0f, 0.0f);
	}
	Vector2 Vector2::One()
	{
		return Vector2(1.0f, 1.0f);
	}
	Vector2 Vector2::Up()
	{
		return Vector2(0.0f, 1.0f);
	}
	Vector2 Vector2::Down()
	{
		return Vector2(0.0f, -1.0f);
	}
	Vector2 Vector2::Right()
	{
		return Vector2(1.0f, 0.0f);
	}
	Vector2 Vector2::Left()
	{
		return Vector2(-1.0f, 0.0f);
	}


	/* Constructors */

	Vector2::Vector2(const float _x, const float _y)
		: x{ _x }, y{ _y }
	{}

	Vector2::Vector2(const Vector2& _vec2)
		: x{ _vec2.x }, y{ _vec2.y }
	{}


	/* Methods */

	void Vector2::Normalize()
	{
		float length = GetMagnitude();
		if (length != 0)
		{
			x /= length;
			y /= length;
		}
	}
	float Vector2::DotProduct(const Vector2& _rhs) const
	{
		return ((x * _rhs.x) + (y * _rhs.y));
	}
	float Vector2::DotProduct(const Vector2& _lhs, const Vector2& _rhs)
	{
		return ((_lhs.x * _rhs.x) + (_lhs.y * _rhs.y));
	}
	Vector2 Vector2::Lerp(const Vector2& _from, const Vector2& _to, float _speed)
	{
		return (1 - _speed) * _from + _speed * _to;
	}
	float Vector2::Angle(Vector2 _a, Vector2 _b)
	{
		return ToDegrees(acos(Vector2::DotProduct(_a, _b) / (_a.GetMagnitude()*_b.GetMagnitude())));
	}
	Vector2 Vector2::Max(Vector2 _a, Vector2 _b)
	{
		Vector2 temp;

		if (_a.x > _b.x)
			temp.x = _a.x;
		else
			temp.x = _b.x;

		if (_a.y > _b.y)
			temp.y = _a.y;
		else
			temp.y = _b.y;

		return temp;
	}
	Vector2 Vector2::Min(Vector2 _a, Vector2 _b)
	{
		Vector2 temp;

		if (_a.x < _b.x)
			temp.x = _a.x;
		else
			temp.x = _b.x;

		if (_a.y < _b.y)
			temp.y = _a.y;
		else
			temp.y = _b.y;

		return temp;
	}
	Vector2 Vector2::MoveTowards(Vector2 _current, Vector2 _target, float _speed)
	{
		Vector2 temp = _target - _current;
		float magnitude = temp.GetMagnitude();

		if (magnitude <= _speed || magnitude == 0.f)
			return _target;

		return _current + temp / magnitude * _speed;
	}


	/* Getters */

	float Vector2::GetDistance(const Vector2& _first, const Vector2& _second)
	{
		return sqrtf((_first.x - _second.x)*(_first.x - _second.x)
			+ (_first.y - _second.y)*(_first.y - _second.y));
	}
	float Vector2::GetDistance(const Vector2& _vec2) const
	{
		return sqrtf((x - _vec2.x)*(x - _vec2.x)
			+ (y - _vec2.y)*(y - _vec2.y));
	}
	float Vector2::GetMagnitude() const
	{
		return sqrtf(x*x + y*y);
	}
	float Vector2::GetSquareMagnitude() const
	{
		return x*x + y*y;
	}
	Vector2 Vector2::GetNormalized() const
	{
		float length = GetMagnitude();

		return Vector2(x / length, y / length);
	}


	/* Operators */

	Vector2 Vector2::operator-() const
	{
		return Vector2(-x, -y);
	}
	float Vector2::operator,(const Vector2& _otherVector) const //DotProduct
	{
		return DotProduct(_otherVector);
	}
	Vector2 Vector2::operator*(const Vector2& _otherVector) const //CrossProduct
	{
		return Vector2(x * _otherVector.x, y * _otherVector.y);
	}
	Vector2 Vector2::operator*(float _value) const
	{
		return Vector2(x * _value, y * _value);
	}
	void Vector2::operator*=(const Vector2& _otherVector)
	{
		Vector2 vec2(x * _otherVector.x, y * _otherVector.y);
		x = vec2.x;
		y = vec2.y;
	}
	Vector2 Vector2::operator/(float _value) const
	{
		return Vector2(x / _value, y / _value);
	}
	Vector2 Vector2::operator+(const Vector2& _otherVector) const
	{
		return Vector2(x + _otherVector.x, y + _otherVector.y);
	}
	void Vector2::operator+=(const Vector2& _otherVector)
	{
		x += _otherVector.x;
		y += _otherVector.y;
	}
	Vector2 Vector2::operator-(const Vector2& _otherVector) const
	{
		return Vector2(x - _otherVector.x, y - _otherVector.y);
	}
	void Vector2::operator-=(const Vector2& _otherVector)
	{
		x -= _otherVector.x;
		y -= _otherVector.y;
	}
	void Vector2::operator=(const Vector2& _otherVector)
	{
		x = _otherVector.x;
		y = _otherVector.y;
	}
	bool Vector2::operator==(const Vector2& _otherVector) const
	{
		if (x == _otherVector.x && y == _otherVector.y)
			return true;
		else
			return false;
	}
	bool Vector2::operator!=(const Vector2& _otherVector) const
	{
		if (x == _otherVector.x && y == _otherVector.y)
			return false;
		else
			return true;
	}
	bool Vector2::operator<(const Vector2& _otherVector) const
	{
		if (GetMagnitude() < _otherVector.GetMagnitude())
			return true;
		else
			return false;
	}
	bool Vector2::operator>(const Vector2& _otherVector) const
	{
		if (GetMagnitude() > _otherVector.GetMagnitude())
			return true;
		else
			return false;
	}
	bool Vector2::operator<=(const Vector2& _otherVector) const
	{
		if (GetMagnitude() <= _otherVector.GetMagnitude())
			return true;
		else
			return false;
	}
	bool Vector2::operator>=(const Vector2& _otherVector) const
	{
		if (GetMagnitude() >= _otherVector.GetMagnitude())
			return true;
		else
			return false;
	}


	/* External Operators */

	Vector2 operator*(float _f, const Vector2& _vector)
	{
		return Vector2(_vector.x * _f, _vector.y * _f);
	}
	Vector2& operator*(float _f, Vector2& _vector)
	{
		_vector.x *= _f;
		_vector.y *= _f;

		return _vector;
	}
	Vector2 operator/(float _f, const Vector2& _vector)
	{
		Vector2 temp;
		if (_vector.x != 0)
			temp.x = _f / _vector.x;
		if (_vector.y != 0)
			temp.y = _f / _vector.y;

		return temp;
	}
	Vector2& operator/(float _f, Vector2& _vector)
	{
		if (_f != 0)
		{
			_vector.x /= _f;
			_vector.y /= _f;
		}

		return _vector;
	}
	std::string& operator+(std::string& _string, const Vector2& _vector)
	{
		_string = "Vec2(";
		_string += std::to_string(_vector.x);
		_string += ", ";
		_string += std::to_string(_vector.y);
		_string += ")\n";

		return _string;
	}
	std::string& operator+=(std::string& _string, const Vector2& _vector)
	{
		_string += "Vec2(";
		_string += std::to_string(_vector.x);
		_string += ", ";
		_string += std::to_string(_vector.y);
		_string += ")\n";

		return _string;
	}
	std::ostream& operator<<(std::ostream& _outStream, const Vector2& _vector)
	{
		return _outStream << "Vec2(" << _vector.x << ", " << _vector.y << ")";
	}
	std::istream& operator>>(std::istream& _inStream, Vector2& _vector)
	{
		char c;
		_inStream >> _vector.x >> c;

		if (c == ',')
			_inStream >> _vector.y;
		else if (c == 'f')
		{
			_inStream >> c;
			if (c == ',')
			{
				_inStream >> _vector.y;
				_inStream >> c;
				if (c == 'f')
				{
					_inStream >> c;
				}
			}
			else
				_vector.x = _vector.y = 0.0;
		}
		else
			_vector.x = _vector.y = 0.0;

		return _inStream;
	}
}