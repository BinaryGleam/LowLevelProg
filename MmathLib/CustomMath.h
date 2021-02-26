#pragma once

#include "Quaternion.h"

namespace CMath
{
	static class CustomMath
	{
		public:
			CustomMath() = delete;
	
			~CustomMath() = delete;
	
			static float Abs(float value)
			{
				if (value < 0.f)
					value *= -1.f;
			}

			static float Inv(float value)
			{
				value *= -1.f;
			}
	
		private:
	
	};
}