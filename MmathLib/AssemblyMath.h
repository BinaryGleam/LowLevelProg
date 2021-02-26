#pragma once
#include <xmmintrin.h>
#include "AVector2.h"

namespace Mmath
{
	static class AssemblyMath
	{
	public:
		AssemblyMath() = delete;

		~AssemblyMath() = delete;

		static float AInv(float value)
		{
			float mask = -0.f;
			__m128 result = _mm_xor_ps(_mm_load_ps(&value), _mm_load_ps(&mask));

			_mm_store_ps(&value, result);
			return value;
		}

		static float AAbs(float value)
		{
			float mask = -value;
			__m128 result = _mm_and_ps(_mm_load_ps(&value), _mm_load_ps(&mask));

			_mm_store_ps(&value, result);
			return value;
		}

	private:

	};

}