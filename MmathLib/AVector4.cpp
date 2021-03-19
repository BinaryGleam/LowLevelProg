#include "AVector4.h"
#include <xmmintrin.h>
#include <string>


namespace Mmath
{
	/* Static functions */
	AVector4 AVector4::Zero()
	{
		return AVector4();
	}

	AVector4 AVector4::One()
	{
		return AVector4(1.0f, 1.0f);
	}

	AVector4 AVector4::Up()
	{
		return AVector4(0.0f, 1.0f);
	}

	AVector4 AVector4::Down()
	{
		return AVector4(0.0f, -1.0f);
	}

	AVector4 AVector4::Right()
	{
		return AVector4(1.0f, 0.0f);
	}

	AVector4 AVector4::Left()
	{
		return AVector4(-1.0f, 0.0f);
	}

	/* Constructors */
	AVector4::AVector4(const float _x, const float _y, const float _z, const float _w)
		: x{ _x }, y{ _y }, z{ _z }, w{ _w }
	{}

	AVector4::AVector4(const AVector4& _vec2)
		: x{ _vec2.x }, y{ _vec2.y }
	{}

	void AVector4::Normalize()
	{
		float length[2] = { GetMagnitude(), GetMagnitude() };
		_mm_store_ps(&x, _mm_div_ps(_mm_load_ps(&x), _mm_load_ps(&length[0])));
	}

	/* Methods */
	float AVector4::DotProduct(const AVector4& _rhs) const
	{
		float toReturn = 0.f;
		float mulResults[4]{ 0.f, 0.f, 0.f, 0.f};
		// multiply x with x and y with y and record it in the mulResults array
		_mm_store_ps(&mulResults[0], _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&_rhs.x)));
		//Sub the result of x*x and y*y that should be in the array
		_mm_store_ss(&toReturn, _mm_add_ss(_mm_load_ss(&mulResults[0]), _mm_load_ss(&mulResults[1])));
		//We SHOULD have our dotProduct
		return toReturn;
	}

	float AVector4::DotProduct(const AVector4& _lhs, const AVector4& _rhs)
	{
		float toReturn = 0.f;
		float mulResults[4]{ 0.f, 0.f, 0.f, 0.f };
		// multiply x with x and y with y and record it in the mulResults array
		_mm_store_ps(&mulResults[0], _mm_mul_ps(_mm_load_ps(&_lhs.x), _mm_load_ps(&_rhs.x)));
		//Sub the result of x*x and y*y that should be in the array
		_mm_store_ss(&toReturn, _mm_add_ss(_mm_load_ss(&mulResults[0]), _mm_load_ss(&mulResults[1])));
		//We SHOULD have our dotProduct
		return toReturn;
	}

	AVector4 AVector4::Lerp(const AVector4& _from, const AVector4& _to, float _speed)
	{
		return (1 - _speed) * _from + _speed * _to;
	}

	float AVector4::Angle(AVector4 _a, AVector4 _b)
	{
		//Ptetre genre faire fonction _mm pour toDegrees
		return ToDegrees(acos(AVector4::DotProduct(_a, _b) / (_a.GetMagnitude() * _b.GetMagnitude())));
	}

	float AVector4::GetDistance(const AVector4& _first, const AVector4& _second)
	{
		float farray[4]{ 0.f, 0.f, 0.f, 0.f };
		float result = 0.0f;

		_mm_store_ps(&farray[0], _mm_sub_ps(_mm_load_ps(&_first.x), _mm_load_ps(&_second.x)));
		_mm_store_ps(&farray[0], _mm_mul_ps(_mm_load_ps(&farray[0]), _mm_load_ps(&farray[0])));
		_mm_store_ss(&result, _mm_add_ss(_mm_load_ss(&farray[0]), _mm_load_ss(&farray[1])));

		return sqrtf(result);
	}

	float AVector4::GetDistance(const AVector4& _vec2) const
	{
		float farray[4]{ 0.f, 0.f, 0.f, 0.f };
		float result = 0.0f;

		_mm_store_ps(&farray[0], _mm_sub_ps(_mm_load_ps(&x), _mm_load_ps(&_vec2.x)));
		_mm_store_ps(&farray[0], _mm_mul_ps(_mm_load_ps(&farray[0]), _mm_load_ps(&farray[0])));
		_mm_store_ss(&result, _mm_add_ss(_mm_load_ss(&farray[0]), _mm_load_ss(&farray[1])));

		return sqrtf(result);
	}

	float AVector4::GetMagnitude() const
	{
		float toReturn = 0.f;
		float mulResults[4]{ 0.f, 0.f, 0.f, 0.f };
		// multiply x with x and y with y and record it in the mulResults array
		_mm_store_ps(&mulResults[0], _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&x)));
		//Sub the result of x*x and y*y that should be in the array
		_mm_store_ss(&toReturn, _mm_add_ss(_mm_load_ss(&mulResults[0]), _mm_load_ss(&mulResults[1])));
		return sqrtf(toReturn);
	}

	float AVector4::GetSquareMagnitude() const
	{
		float toReturn = 0.f;
		float mulResults[4]{ 0.f, 0.f, 0.f, 0.f };
		// multiply x with x and y with y and record it in the mulResults array
		_mm_store_ps(&mulResults[0], _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&x)));
		//Sub the result of x*x and y*y that should be in the array
		_mm_store_ss(&toReturn, _mm_add_ss(_mm_load_ss(&mulResults[0]), _mm_load_ss(&mulResults[1])));
		return toReturn;
	}

	AVector4 AVector4::GetNormalized() const
	{
		float length[4] = { GetMagnitude(), GetMagnitude(), GetMagnitude(), GetMagnitude() };
		AVector4 toReturn;
		_mm_store_ps(&toReturn.x, _mm_div_ps(_mm_load_ps(&x), _mm_load_ps(&length[0])));
		return toReturn;
	}

	/* Operators */
	AVector4 AVector4::operator-()
	{
		float mask[2] = { -0.f, -0.f };
		AVector4 toReturn = *this;
		__m128 result = _mm_xor_ps(_mm_load_ps(&toReturn.x), _mm_load_ps(&mask[0]));

		_mm_store_ps(&toReturn.x, result);
		return toReturn;
	}

	float AVector4::operator,(const AVector4& _otherVector) const
	{
		return DotProduct(_otherVector);
	}

	AVector4 AVector4::operator*(const AVector4& _otherVector) const
	{
		AVector4 newVector;

		_mm_store_ps(&newVector.x, _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&_otherVector.x)));

		return newVector;
	}

	AVector4 AVector4::operator*(float _value) const
	{
		AVector4 newVector = *this;
		float values[2]{ _value,_value };

		_mm_store_ps(&newVector.x, _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&values[0])));

		return newVector;
	}

	void AVector4::operator*=(const AVector4& _otherVector)
	{
		_mm_store_ps(&x, _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&_otherVector.x)));
	}

	AVector4 AVector4::operator/(float _value) const
	{
		AVector4 newVector = *this;
		float values[2]{ _value,_value };

		_mm_store_ps(&newVector.x, _mm_div_ps(_mm_load_ps(&x), _mm_load_ps(&values[0])));

		return newVector;
	}

	AVector4 AVector4::operator+(const AVector4& _otherVector) const
	{
		AVector4 newVector;

		__m128 result = _mm_add_ps(_mm_load_ps(&x), _mm_load_ps(&_otherVector.x));

		_mm_store_ps(&newVector.x, result);

		return newVector;
	}

	void AVector4::operator+=(const AVector4& _otherVector)
	{
		__m128 result = _mm_add_ps(_mm_load_ps(&x), _mm_load_ps(&_otherVector.x));

		_mm_store_ps(&x, result);
	}

	AVector4 AVector4::operator-(const AVector4& _otherVector) const
	{
		AVector4 newVector;

		__m128 result = _mm_sub_ps(_mm_load_ps(&x), _mm_load_ps(&_otherVector.x));
		_mm_store_ps(&newVector.x, result);

		return newVector;
	}

	void AVector4::operator-=(const AVector4& _otherVector)
	{
		__m128 result = _mm_sub_ps(_mm_load_ps(&x), _mm_load_ps(&_otherVector.x));
		_mm_store_ps(&x, result);
	}

	void AVector4::operator=(const AVector4& _otherVector)
	{
		_mm_store_ps(&x, _mm_load_ps(&_otherVector.x));
	}

	bool AVector4::operator==(const AVector4& _otherVector) const
	{
		return x == _otherVector.x && y == _otherVector.y;
	}

	bool AVector4::operator!=(const AVector4& _otherVector) const
	{
		return x == _otherVector.x && y == _otherVector.y;
	}
	bool AVector4::operator<(const AVector4& _otherVector) const
	{
		return GetMagnitude() < _otherVector.GetMagnitude();
	}
	bool AVector4::operator>(const AVector4& _otherVector) const
	{
		return GetMagnitude() > _otherVector.GetMagnitude();
	}
	bool AVector4::operator<=(const AVector4& _otherVector) const
	{
		return GetMagnitude() <= _otherVector.GetMagnitude();
	}
	bool AVector4::operator>=(const AVector4& _otherVector) const
	{
		return GetMagnitude() >= _otherVector.GetMagnitude();
	}



	AVector4 operator*(float _f, const AVector4& _vector)
	{
		AVector4 newVector;
		float values[2]{ _f, _f };
		_mm_storer_ps(&newVector.x, _mm_mul_ps(_mm_load_ps(&_vector.x), _mm_load_ps(&values[0])));
		return newVector;
	}

	AVector4& operator*(float _f, AVector4& _vector)
	{
		float values[2]{ _f, _f };
		_mm_storer_ps(&_vector.x, _mm_mul_ps(_mm_load_ps(&_vector.x), _mm_load_ps(&values[0])));
		return _vector;
	}

	AVector4 operator/(float _f, const AVector4& _vector)
	{
		AVector4 newVector;
		float values[2]{ _f, _f };
		_mm_storer_ps(&newVector.x, _mm_div_ps(_mm_load_ps(&_vector.x), _mm_load_ps(&values[0])));
		return newVector;
	}

	AVector4& operator/(float _f, AVector4& _vector)
	{
		float values[2]{ _f, _f };
		_mm_storer_ps(&_vector.x, _mm_div_ps(_mm_load_ps(&_vector.x), _mm_load_ps(&values[0])));
		return _vector;
	}

	std::string& operator+(std::string& _string, const AVector4& _vector)
	{
		_string = "Vec2(";
		_string += std::to_string(_vector.x);
		_string += ", ";
		_string += std::to_string(_vector.y);
		_string += ")\n";

		return _string;
	}

	std::string& operator+=(std::string& _string, const AVector4& _vector)
	{
		_string += "Vec2(";
		_string += std::to_string(_vector.x);
		_string += ", ";
		_string += std::to_string(_vector.y);
		_string += ")\n";

		return _string;
	}

	std::ostream& operator<<(std::ostream& _outStream, const AVector4& _vector)
	{
		return _outStream << "Vec4(" << _vector.x << ", " << _vector.y << ", " << _vector.z << ", " << _vector.w << ")";
	}

	std::istream& operator>>(std::istream& _inStream, AVector4& _vector)
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
