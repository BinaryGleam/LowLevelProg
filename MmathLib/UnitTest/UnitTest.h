#ifndef __UNITTEST_H__
#define __UNITTEST_H__

#include <Windows.h>
#include "../Quaternion.h"

namespace CMath
{
	struct UnitTest
	{
		/* Method */

		static const void Run(bool _pause);

		/* Vector2 */

		static const void Vector2AllTest();
		static const void Vector2Constructors();
		static const void Vector2Methods();
		static const void Vector2Getters();
		static const void Vector2Operators();


		/* Vector3 */

		static const void Vector3AllTest();
		static const void Vector3Constructors();
		static const void Vector3Methods();
		static const void Vector3Getters();
		static const void Vector3Operators();


		/* Vector4 */

		static const void Vector4AllTest();
		static const void Vector4Constructors();
		static const void Vector4Methods();
		static const void Vector4Getters();
		static const void Vector4Operators();


		/* Matrix */

		static const void MatrixAllTest();
		static const void MatrixConstructors();
		static const void MatrixMethods();
		static const void MatrixStaticMethods();
		static const void MatrixGetters();
		static const void MatrixOperators();


		/* Quaternion */

		static const void QuaternionAllTest();
		static const void QuaternionConstructors();
		static const void QuaternionMethods();
		static const void QuaternionStaticMethods();
		static const void QuaternionGetters();
		static const void QuaternionOperators();
	};
}
namespace Log
{
	struct Out
	{
		enum Color
		{
			BLACK = 0 | FOREGROUND_INTENSITY,
			WHITE = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
			GREY = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN,
			RED = FOREGROUND_RED | FOREGROUND_INTENSITY,
			CARDINAL_RED = FOREGROUND_RED,
			BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
			DARK_BLUE = FOREGROUND_BLUE,
			GREEN = FOREGROUND_GREEN,
			FLASHY_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
			CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
			MAGENTA = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY,
			YELLOW = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
		};


		/* Color Methods */

		static const void Separate(bool, std::string);
		static const void ChangeColor(Color);
	};
}
#endif