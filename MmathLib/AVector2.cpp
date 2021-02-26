#include "AVector2.h"
#include <xmmintrin.h>
#include <string>


namespace Mmath
{
	/* Constructors */
	AVector2::AVector2(const float _x, const float _y)
		: x{ _x }, y{ _y }
	{}

	AVector2::AVector2(const AVector2& _vec2)
		: x{ _vec2.x }, y{ _vec2.y }
	{}

	/* Operators */
	AVector2 AVector2::operator-()
	{
		float mask[2] = {-0.f, -0.f};
		AVector2 toReturn = *this;
		__m128 result = _mm_xor_ps(_mm_load_ps(&toReturn.x), _mm_load_ps(&mask[0]));

		_mm_store_ps(&toReturn.x, result);
		return toReturn;
	}

	AVector2 AVector2::operator*(float _value) const
	{
		AVector2 newVector = *this;
		float values[2] { _value,_value };
		
		_mm_store_ps(&newVector.x, _mm_mul_ps(_mm_load_ps(&x), _mm_load_ps(&values[0])));

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
		return false;
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
