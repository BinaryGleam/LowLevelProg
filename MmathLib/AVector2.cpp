#include "AVector2.h"
#include <xmmintrin.h>
#include <string>


namespace Mmath
{
	/* Static functions */
	AVector2 AVector2::Zero()
	{
		return AVector2();
	}

	AVector2 AVector2::One()
	{
		return AVector2(1.0f,1.0f);
	}

	AVector2 AVector2::Up()
	{
		return AVector2(0.0f,1.0f);
	}

	AVector2 AVector2::Down()
	{
		return AVector2(0.0f,-1.0f);
	}

	AVector2 AVector2::Right()
	{
		return AVector2(1.0f,0.0f);
	}

	AVector2 AVector2::Left()
	{
		return AVector2(-1.0f,0.0f);
	}

	/* Constructors */
	AVector2::AVector2(const float _x, const float _y)
		: x{ _x }, y{ _y }
	{}

	AVector2::AVector2(const AVector2& _vec2)
		: x{ _vec2.x }, y{ _vec2.y }
	{}

	void AVector2::Normalize()
	{
		float length[2] = { GetMagnitude(), GetMagnitude() };
		_mm_store_ps(&x, _mm_div_ps(_mm_load_ps(&x), _mm_load_ps(&length[0])));
	}

	/* Methods */
	float AVector2::DotProduct(const AVector2& _rhs) const
	{
		float toReturn = 0.f;
		float mulResults[2] { 0.f, 0.f };
		// multiply x with x and y with y and record it in the mulResults array
		_mm_store_ps(&mulResults[0], _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&_rhs.x)));
		//Sub the result of x*x and y*y that should be in the array
		_mm_store_ps(&toReturn, _mm_add_ss(_mm_load_ss(&mulResults[0]),_mm_load_ss(&mulResults[1])));
		//We SHOULD have our dotProduct
		return toReturn;
	}

	float AVector2::DotProduct(const AVector2& _lhs, const AVector2& _rhs)
	{
		float toReturn = 0.f;
		float mulResults[2]{ 0.f, 0.f };
		// multiply x with x and y with y and record it in the mulResults array
		_mm_store_ps(&mulResults[0], _mm_mul_ps(_mm_load_ps(&_lhs.x), _mm_load_ps(&_rhs.x)));
		//Sub the result of x*x and y*y that should be in the array
		_mm_store_ps(&toReturn, _mm_add_ss(_mm_load_ss(&mulResults[0]), _mm_load_ss(&mulResults[1])));
		//We SHOULD have our dotProduct
		return toReturn;
	}

	AVector2 AVector2::Lerp(const AVector2& _from, const AVector2& _to, float _speed)
	{
		return (1 - _speed) * _from + _speed * _to;
	}

	float AVector2::Angle(AVector2 _a, AVector2 _b)
	{
		//Ptetre genre faire fonction _mm pour toDegrees
		return ToDegrees(acos(AVector2::DotProduct(_a, _b) / (_a.GetMagnitude() * _b.GetMagnitude())));
	}

	float AVector2::GetDistance(const AVector2& _first, const AVector2& _second)
	{
		float farray[2]{ 0.0f,0.0f };
		float result = 0.0f;

		_mm_store_ps(&farray[0], _mm_sub_ps(_mm_load_ps(&_first.x), _mm_load_ps(&_second.x)));
		_mm_store_ps(&farray[0], _mm_mul_ps(_mm_load_ps(&farray[0]), _mm_load_ps(&farray[0])));
		_mm_store_ps(&result, _mm_add_ss(_mm_load_ss(&farray[0]), _mm_load_ss(&farray[1])));

		return sqrtf(result);
	}

	float AVector2::GetDistance(const AVector2& _vec2) const
	{
		float farray[2]{0.0f,0.0f};
		float result = 0.0f;

		_mm_store_ps(&farray[0], _mm_sub_ps(_mm_load_ps(&x), _mm_load_ps(&_vec2.x)));
		_mm_store_ps(&farray[0], _mm_mul_ps(_mm_load_ps(&farray[0]), _mm_load_ps(&farray[0])));
		_mm_store_ps(&result, _mm_add_ss(_mm_load_ss(&farray[0]), _mm_load_ss(&farray[1])));

		return sqrtf(result);
	}

	float AVector2::GetMagnitude() const
	{
		float toReturn = 0.f;
		float mulResults[2]{ 0.f, 0.f };
		// multiply x with x and y with y and record it in the mulResults array
		_mm_store_ps(&mulResults[0], _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&x)));
		//Sub the result of x*x and y*y that should be in the array
		_mm_store_ps(&toReturn, _mm_add_ss(_mm_load_ss(&mulResults[0]), _mm_load_ss(&mulResults[1])));
		return sqrtf(toReturn);
	}

	float AVector2::GetSquareMagnitude() const
	{
		float toReturn = 0.f;
		float mulResults[2]{ 0.f, 0.f };
		// multiply x with x and y with y and record it in the mulResults array
		_mm_store_ps(&mulResults[0], _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&x)));
		//Sub the result of x*x and y*y that should be in the array
		_mm_store_ps(&toReturn, _mm_add_ss(_mm_load_ss(&mulResults[0]), _mm_load_ss(&mulResults[1])));
		return toReturn;
	}

	AVector2 AVector2::GetNormalized() const
	{
		float length[2] = { GetMagnitude(), GetMagnitude() };
		AVector2 toReturn;
		_mm_store_ps(&toReturn.x, _mm_div_ps(_mm_load_ps(&x), _mm_load_ps(&length[0])));
		return toReturn;
	}

	/* Operators */
	AVector2 AVector2::operator-()
	{
		float mask[2] = {-0.f, -0.f};
		AVector2 toReturn = *this;
		__m128 result = _mm_xor_ps(_mm_load_ps(&toReturn.x), _mm_load_ps(&mask[0]));

		_mm_store_ps(&toReturn.x, result);
		return toReturn;
	}

	float AVector2::operator,(const AVector2& _otherVector) const
	{
		return DotProduct(_otherVector);
	}

	AVector2 AVector2::operator*(const AVector2& _otherVector) const
	{
		AVector2 newVector;

		_mm_store_ps(&newVector.x, _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&_otherVector.x)));

		return newVector;
	}

	AVector2 AVector2::operator*(float _value) const
	{
		AVector2 newVector = *this;
		float values[2] { _value,_value };
		
		_mm_store_ps(&newVector.x, _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&values[0])));

		return newVector;
	}

	void AVector2::operator*=(const AVector2& _otherVector)
	{
		_mm_store_ps(&x, _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&_otherVector.x)));
	}

	AVector2 AVector2::operator/(float _value) const
	{
		AVector2 newVector = *this;
		float values[2]{ _value,_value };

		_mm_store_ps(&newVector.x, _mm_div_ps(_mm_load_ps(&x), _mm_load_ps(&values[0])));

		return newVector;
	}

	AVector2 AVector2::operator+(const AVector2& _otherVector) const
	{
		AVector2 newVector;
		
		__m128 result = _mm_add_ps(_mm_load_ps(&x), _mm_load_ps(&_otherVector.x));

		_mm_store_ps(&newVector.x, result);

		return newVector;
	}

	void AVector2::operator+=(const AVector2& _otherVector)
	{
		__m128 result = _mm_add_ps(_mm_load_ps(&x), _mm_load_ps(&_otherVector.x));

		_mm_store_ps(&x, result);
	}

	AVector2 AVector2::operator-(const AVector2& _otherVector) const
	{
		AVector2 newVector;

		__m128 result = _mm_sub_ps(_mm_load_ps(&x), _mm_load_ps(&_otherVector.x));
		_mm_store_ps(&newVector.x, result);

		return newVector;
	}

	void AVector2::operator-=(const AVector2& _otherVector)
	{
		__m128 result = _mm_sub_ps(_mm_load_ps(&x), _mm_load_ps(&_otherVector.x));
		_mm_store_ps(&x, result);
	}

	void AVector2::operator=(const AVector2& _otherVector)
	{
		_mm_store_ps(&x, _mm_load_ps(&_otherVector.x));
	}

	bool AVector2::operator==(const AVector2& _otherVector) const
	{
		return x == _otherVector.x && y == _otherVector.y;
	}

	bool AVector2::operator!=(const AVector2& _otherVector) const
	{
		return x == _otherVector.x && y == _otherVector.y;
	}
	bool AVector2::operator<(const AVector2& _otherVector) const
	{
		return GetMagnitude() < _otherVector.GetMagnitude();
	}
	bool AVector2::operator>(const AVector2& _otherVector) const
	{
		return GetMagnitude() > _otherVector.GetMagnitude();
	}
	bool AVector2::operator<=(const AVector2& _otherVector) const
	{
		return GetMagnitude() <= _otherVector.GetMagnitude();
	}
	bool AVector2::operator>=(const AVector2& _otherVector) const
	{
		return GetMagnitude() >= _otherVector.GetMagnitude();
	}



	AVector2 operator*(float _f, const AVector2& _vector)
	{
		AVector2 newVector;
		float values[2] { _f, _f };
		_mm_storer_ps(&newVector.x, _mm_mul_ps(_mm_load_ps(&_vector.x), _mm_load_ps(&values[0])));
		return newVector;
	}

	AVector2& operator*(float _f, AVector2& _vector)
	{
		float values[2]{ _f, _f };
		_mm_storer_ps(&_vector.x, _mm_mul_ps(_mm_load_ps(&_vector.x), _mm_load_ps(&values[0])));
		return _vector;
	}

	AVector2 operator/(float _f, const AVector2& _vector)
	{
		AVector2 newVector;
		float values[2]{ _f, _f };
		_mm_storer_ps(&newVector.x, _mm_div_ps(_mm_load_ps(&_vector.x), _mm_load_ps(&values[0])));
		return newVector;
	}

	AVector2& operator/(float _f, AVector2& _vector)
	{
		float values[2]{ _f, _f };
		_mm_storer_ps(&_vector.x, _mm_div_ps(_mm_load_ps(&_vector.x), _mm_load_ps(&values[0])));
		return _vector;
	}

	std::string& operator+(std::string& _string, const AVector2& _vector)
	{
		_string = "Vec2(";
		_string += std::to_string(_vector.x);
		_string += ", ";
		_string += std::to_string(_vector.y);
		_string += ")\n";

		return _string;
	}

	std::string& operator+=(std::string& _string, const AVector2& _vector)
	{
		_string += "Vec2(";
		_string += std::to_string(_vector.x);
		_string += ", ";
		_string += std::to_string(_vector.y);
		_string += ")\n";

		return _string;
	}

	std::ostream& operator<<(std::ostream& _outStream, const AVector2& _vector)
	{
		return _outStream << "Vec2(" << _vector.x << ", " << _vector.y << ")";
	}

	std::istream& operator>>(std::istream& _inStream, AVector2& _vector)
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
