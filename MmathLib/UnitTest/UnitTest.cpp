#include "UnitTest.h"

#define Color_Green Out::ChangeColor(Out::FLASHY_GREEN);
#define Color_Cyan Out::ChangeColor(Out::CYAN);
#define Color_White Out::ChangeColor(Out::WHITE);
#define Color_Yellow Out::ChangeColor(Out::YELLOW);

using namespace Log;

namespace CMath
{
	/* Method */

	const void UnitTest::Run(bool _pause)
	{
		Out::ChangeColor(Out::RED);
		std::cout << "PART" << std::endl;
		Out::ChangeColor(Out::MAGENTA);
		std::cout << "INFORMATION" << std::endl;
		Out::ChangeColor(Out::WHITE);
		std::cout << "TITLE" << std::endl;
		Out::ChangeColor(Out::YELLOW);
		std::cout << "VARIABLE" << std::endl;
		Out::ChangeColor(Out::FLASHY_GREEN);
		std::cout << "FUNCTION" << std::endl;
		Out::ChangeColor(Out::CYAN);
		std::cout << "RESULT" << std::endl;
		std::cout << "\n\n\n";


		Out::Separate(false, "VECTOR 2");
		UnitTest::Vector2AllTest();

		Out::Separate(true, "VECTOR 3");
		UnitTest::Vector3AllTest();

		Out::Separate(true, "VECTOR 4");
		UnitTest::Vector4AllTest();

		Out::Separate(true, "MATRIX");
		UnitTest::MatrixAllTest();

		Out::Separate(true, "QUATERNION");
		UnitTest::QuaternionAllTest();

		Out::Separate(true, "");
		if(_pause)
			system("pause");
	}


	/* Vector2 */

	const void UnitTest::Vector2AllTest()
	{
		Vector2Constructors();
		Vector2Methods();
		Vector2Getters();
		Vector2Operators();
	}
	const void UnitTest::Vector2Constructors()
	{
		Out::ChangeColor(Out::MAGENTA);
		std::cout << "Vector2(x, y)\n\n";
		Color_White
		std::cout << "\nVector2 Constructors Test:" << std::endl;
		Color_Cyan
			Vector2 v1;
		Vector2 v2(5, 9);
		Vector2 v3(v2);
		std::cout << v1 << v2 << v3;
	}
	const void UnitTest::Vector2Methods()
	{
		Color_White
		std::cout << "\nVector2 Methods Test:" << std::endl;
		Color_Yellow
		Vector2 v1(1, 9);
		Vector2 v2(7, 3);
		std::cout << "Vector v1:\t\t\t" << v1;
		std::cout << "Vector v2:\t\t\t" << v2;
		v1.Normalize();
		Color_Green
			std::cout << "Normalize (v1):\t\t\t";
		Color_Cyan
			std::cout << v1;
		Color_Green
			std::cout << "DotProduct (v1.v2):\t\t";
		Color_Cyan
			std::cout << v1.DotProduct(v2) << std::endl;
		Color_Green
			std::cout << "Lerp (v1, v2):\t\t\t";
		Color_Cyan
			std::cout << Vector2::Lerp(v1, v2, 0.2f);
		Color_Green
			std::cout << "Angle (v1,v2):\t\t\t";
		Color_Cyan
			std::cout << Vector2::Angle(v1, v2) << std::endl;
		Color_Green
			std::cout << "Min (v1, v2):\t\t\t";
		Color_Cyan
			std::cout << Vector2::Min(v1, v2);
		Color_Green
			std::cout << "Max (v1, v2):\t\t\t";
		Color_Cyan
			std::cout << Vector2::Max(v1, v2);
		Color_Green
			std::cout << "MoveTowards (v1, v2, 0.1f):\t";
		Color_Cyan
			std::cout << Vector2::MoveTowards(v1, v2, 0.1f);
	}
	const void UnitTest::Vector2Getters()
	{
		Color_White
		std::cout << "\nVector2 Getters Test:" << std::endl;
		Color_Yellow
		Vector2 v1(2, 9);
		Vector2 v2(7, 3);
		std::cout << "Vector v1:\t\t" << v1;
		std::cout << "Vector v2:\t\t" << v2;
		Color_Green
			std::cout << "Distance (v1, v2):\t";
		Color_Cyan
			std::cout << v1.GetDistance(v2) << std::endl;
		Color_Green
			std::cout << "Magnitude (v1):\t\t";
		Color_Cyan
			std::cout << v1.GetMagnitude() << std::endl;
		Color_Green
			std::cout << "SquareMagnitude (v1):\t";
		Color_Cyan
			std::cout << v1.GetSquareMagnitude() << std::endl;
		Color_Green
			std::cout << "Normalized (v2):\t";
		Color_Cyan
			std::cout << v2.GetNormalized();
	}
	const void UnitTest::Vector2Operators()
	{
		Color_White
		std::cout << "\nVector2 Operators Test:" << std::endl;
		Color_Yellow
		Vector2 v1(3, 7);
		Vector2 v2(9, 1);
		std::cout << "Vector v1:\t\t\t\t" << v1;
		std::cout << "Vector v2:\t\t\t\t" << v2;
		Color_Green
			std::cout << "Opposite operator (v1):\t\t\t";
		Color_Cyan
			std::cout << -v1;
		Color_Green
			std::cout << "DotProduct operator (v1,v2):\t\t";
		Color_Cyan
			std::cout << (v1, v2) << std::endl;
		Color_Green
			std::cout << "Vector2*Vector2 (v1*v2):\t\t";
		Color_Cyan
			std::cout << v1 * v2;
		Color_Green
			std::cout << "Vector2*float (v2*2):\t\t\t";
		Color_Cyan
			std::cout << v2 * 2;
		Color_Green
			std::cout << "Vector2+Vector2 (v1+v2):\t\t";
		Color_Cyan
			std::cout << v1 + v2;
		Color_Green
			std::cout << "Vector2-Vector2 (v1-v2):\t\t";
		Color_Cyan
			std::cout << v1 - v2;
		Color_Green
			std::cout << "float*Vector2 (3*v2):\t\t\t";
		Color_Cyan
			std::cout << 3 * v2;
		Color_Green
			std::cout << "float/Vector2 (3/Vector2(3,3)):\t\t";
		Color_Cyan
			std::cout << 3 / Vector2(3, 3);
	}


	/* Vector3 */

	const void UnitTest::Vector3AllTest()
	{
		Vector3Constructors();
		Vector3Methods();
		Vector3Getters();
		Vector3Operators();
	}
	const void UnitTest::Vector3Constructors()
	{
		Out::ChangeColor(Out::MAGENTA);
		std::cout << "Vector3(x, y, z)\n\n";
		Color_White
		std::cout << "\nVector3 Constructors Test:" << std::endl;
		Color_Cyan
			Vector3 v1;
		Vector3 v2(5, 9, 1);
		Vector3 v3(v2);
		Vector3 v4(Vector2().Up());
		std::cout << v1 << v2 << v3 << v4;
	}
	const void UnitTest::Vector3Methods()
	{
		Color_White
		std::cout << "\nVector3 Methods Test:" << std::endl;
		Color_Yellow
		Vector3 v1(1, 9, 3);
		Vector3 v2(7, 3, 9);
		std::cout << "Vector v1:\t\t\t" << v1;
		std::cout << "Vector v2:\t\t\t" << v2;
		v1.Normalize();
		Color_Green
			std::cout << "Normalize (v1):\t\t\t";
		Color_Cyan
			std::cout << v1;
		Color_Green
			std::cout << "CrossProduct (v1xv2):\t\t";
		Color_Cyan
			std::cout << v1.CrossProduct(v2);
		Color_Green
			std::cout << "DotProduct (v1.v2):\t\t";
		Color_Cyan
			std::cout << v1.DotProduct(v2) << std::endl;
		Color_Green
			std::cout << "Lerp (v1,v2):\t\t\t";
		Color_Cyan
			std::cout << Vector3::Lerp(v1, v2, 0.2f);
		Color_Green
			std::cout << "Angle (v1,v2):\t\t\t";
		Color_Cyan
			std::cout << Vector3::Angle(v1, v2) << std::endl;
		Color_Green
			std::cout << "Min (v1, v2):\t\t\t";
		Color_Cyan
			std::cout << Vector3::Min(v1, v2);
		Color_Green
			std::cout << "Max (v1, v2):\t\t\t";
		Color_Cyan
			std::cout << Vector3::Max(v1, v2);
		Color_Green
			std::cout << "MoveTowards (v1, v2, 0.1f):\t";
		Color_Cyan
			std::cout << Vector3::MoveTowards(v1, v2, 0.1f);
	}
	const void UnitTest::Vector3Getters()
	{
		Color_White
		std::cout << "\nVector3 Getters Test:" << std::endl;
		Color_Yellow
		Vector3 v1(2, 9, 3);
		Vector3 v2(7, 3, 9);
		std::cout << "Vector v1:\t\t" << v1;
		std::cout << "Vector v2:\t\t" << v2;
		Color_Green
			std::cout << "Distance2D (v1,v2):\t";
		Color_Cyan
			std::cout << v1.GetDistance2D(v2) << std::endl;
		Color_Green
			std::cout << "Distance (v2):\t\t";
		Color_Cyan
			std::cout << v1.GetDistance(v2) << std::endl;
		Color_Green
			std::cout << "Magnitude (v1):\t\t";
		Color_Cyan
			std::cout << v1.GetMagnitude() << std::endl;
		Color_Green
			std::cout << "SquareMagnitude (v1):\t";
		Color_Cyan
			std::cout << v1.GetSquareMagnitude() << std::endl;
		Color_Green
			std::cout << "Normalized (v2):\t";
		Color_Cyan
			std::cout << v2.GetNormalized();
	}
	const void UnitTest::Vector3Operators()
	{
		Color_White
		std::cout << "\nVector3 Operators Test:" << std::endl;
		Color_Yellow
		Vector3 v1(3, 7, 9);
		Vector3 v2(9, 1, 7);
		std::cout << "Vector v1:\t\t\t\t" << v1;
		std::cout << "Vector v2:\t\t\t\t" << v2;
		Color_Green
			std::cout << "Opposite operator (v1):\t\t\t";
		Color_Cyan
			std::cout << -v1;
		Color_Green
			std::cout << "DotProduct operator (v1,v2):\t\t";
		Color_Cyan
			std::cout << (v1, v2) << std::endl;
		Color_Green
			std::cout << "Vector3*Vector3 (v1*v2):\t\t";
		Color_Cyan
			std::cout << v1 * v2;
		Color_Green
			std::cout << "Vector3*float (v2*2):\t\t\t";
		Color_Cyan
			std::cout << v2 * 2;
		Color_Green
			std::cout << "Vector3+Vector3 (v1+v2):\t\t";
		Color_Cyan
			std::cout << v1 + v2;
		Color_Green
			std::cout << "Vector3+Vector2 (v1+Vector3(1,6,7)):\t";
		Color_Cyan
			std::cout << v1 + Vector2(1, 6);
		Color_Green
			std::cout << "Vector3-Vector3 (v1-v2):\t\t";
		Color_Cyan
			std::cout << v1 - v2;
		Color_Green
			std::cout << "Vector3-Vector2 (v1-Vector3(1,6,7)):\t";
		Color_Cyan
			std::cout << v1 - Vector2(1, 6);
		Color_Green
			std::cout << "float*Vector3 (3*v2):\t\t\t";
		Color_Cyan
			std::cout << 3 * v2;
		Color_Green
			std::cout << "float/Vector3 (3/Vector3(3,3,3)):\t";
		Color_Cyan
			std::cout << 3 / Vector3(3, 3, 3);
		Color_Green
			std::cout << "Vector2+Vector3 (Vector2(4,9)+v1):\t";
		Color_Cyan
			std::cout << Vector2(4, 9) + v1;
		Color_Green
			std::cout << "Vector2-Vector3 (Vector2(4,9)-v1):\t";
		Color_Cyan
			std::cout << Vector2(4, 9) - v1;
	}


	/* Vector4 */

	const void UnitTest::Vector4AllTest()
	{
		Vector4Constructors();
		Vector4Methods();
		Vector4Getters();
		Vector4Operators();
	}
	const void UnitTest::Vector4Constructors()
	{
		Out::ChangeColor(Out::MAGENTA);
		std::cout << "Vector4(x, y, z, w)\n\n";
		Color_White
		std::cout << "\nVector4 Constructors Test:" << std::endl;
		Color_Cyan
			Vector4 v1;
		Vector4 v2(5, 9, 1, 3);
		Vector4 v3(v2);
		Vector4 v4(Vector3().Forward());
		std::cout << v1 << v2 << v3 << v4;
	}
	const void UnitTest::Vector4Methods()
	{
		Color_White
		std::cout << "\nVector4 Methods Test:" << std::endl;
		Color_Yellow
		Vector4 v1(1, 9, 3, 7);
		Vector4 v2(7, 3, 9, 1);
		std::cout << "Vector v1:\t\t\t" << v1;
		std::cout << "Vector v2:\t\t\t" << v2;
		v1.Homogenize();
		Color_Green
			std::cout << "Homogenize (v1):\t\t";
		Color_Cyan
			std::cout << v1;
		v1.Normalize();
		Color_Green
			std::cout << "Normalize (v1):\t\t\t";
		Color_Cyan
			std::cout << v1;
		Color_Green
			std::cout << "DotProduct (v1.v2):\t\t";
		Color_Cyan
			std::cout << v1.DotProduct(v2) << std::endl;
		Color_Green
			std::cout << "Lerp (v1,v2):\t\t\t";
		Color_Cyan
			std::cout << Vector4::Lerp(v1, v2, 0.2f);
		Color_Green
			std::cout << "MoveTowards (v1, v2, 0.1f):\t";
		Color_Cyan
			std::cout << Vector4::MoveTowards(v1, v2, 0.1f);
	}
	const void UnitTest::Vector4Getters()
	{
		Color_White
		std::cout << "\nVector4 Getters Test:" << std::endl;
		Color_Yellow
		Vector4 v1(2, 9, 3, 7);
		Vector4 v2(7, 3, 9, 2);
		std::cout << "Vector v1:\t\t" << v1;
		std::cout << "Vector v2:\t\t" << v2;
		Color_Green
			std::cout << "Distance2D (v1,v2):\t";
		Color_Cyan
			std::cout << v1.GetDistance2D(v2) << std::endl;
		Color_Green
			std::cout << "Distance (v1,v2):\t";
		Color_Cyan
			std::cout << v1.GetDistance(v2) << std::endl;
		Color_Green
			std::cout << "Magnitude (v1):\t\t";
		Color_Cyan
			std::cout << v1.GetMagnitude() << std::endl;
		Color_Green
			std::cout << "SquareMagnitude (v1):\t";
		Color_Cyan
			std::cout << v1.GetSquareMagnitude() << std::endl;
		Color_Green
			std::cout << "Normalized (v2):\t";
		Color_Cyan
			std::cout << v2.GetNormalized();
	}
	const void UnitTest::Vector4Operators()
	{
		Color_White
		std::cout << "\nVector4 Operators Test:" << std::endl;
		Color_Yellow
		Vector4 v1(3, 7, 9, 1);
		Vector4 v2(9, 1, 7, 3);
		std::cout << "Vector v1:\t\t\t\t" << v1;
		std::cout << "Vector v2:\t\t\t\t" << v2;
		Color_Green
			std::cout << "Opposite operator (v1):\t\t\t";
		Color_Cyan
			std::cout << -v1;
		Color_Green
			std::cout << "DotProduct operator (v1,v2):\t\t";
		Color_Cyan
			std::cout << (v1, v2) << std::endl;
		Color_Green
			std::cout << "Vector4*Vector4 (v1*v2):\t\t";
		Color_Cyan
			std::cout << v1 * v2;
		Color_Green
			std::cout << "Vector4*float (v2*2):\t\t\t";
		Color_Cyan
			std::cout << v2 * 2;
		Color_Green
			std::cout << "Vector4+Vector4 (v1+v2):\t\t";
		Color_Cyan
			std::cout << v1 + v2;
		Color_Green
			std::cout << "Vector4+Vector3 (v1+Vector3(1,6,7)):\t";
		Color_Cyan
			std::cout << v1 + Vector3(1, 6, 7);
		Color_Green
			std::cout << "Vector4-Vector4 (v1-v2):\t\t";
		Color_Cyan
			std::cout << v1 - v2;
		Color_Green
			std::cout << "Vector4-Vector3 (v1-Vector3(1,6,7)):\t";
		Color_Cyan
			std::cout << v1 - Vector3(1, 6, 7);
		Color_Green
			std::cout << "float*Vector4 (3*v2):\t\t\t";
		Color_Cyan
			std::cout << 3 * v2;
		Color_Green
			std::cout << "float/Vector4 (3/Vector4(3,3,3,3)):\t";
		Color_Cyan
			std::cout << 3 / Vector4(3, 3, 3, 3);
		Color_Green
			std::cout << "Vector3+Vector4 (Vector3(4,9,7)+v1):\t";
		Color_Cyan
			std::cout << Vector3(4, 9, 7) + v1;
		Color_Green
			std::cout << "Vector3-Vector4 (Vector3(4,9,7)-v1):\t";
		Color_Cyan
			std::cout << Vector3(4, 9, 7) - v1;
	}


	/* Matrix */

	const void UnitTest::MatrixAllTest()
	{
		MatrixConstructors();
		MatrixMethods();
		MatrixStaticMethods();
		MatrixGetters();
		MatrixOperators();
	}
	const void UnitTest::MatrixConstructors()
	{
		Color_White
		std::cout << "\nMatrix Constructors Test:" << std::endl;
		Color_Cyan
			Matrix m1;
		float temp[16];
		for (int i = 0; i < 16; i++)
			temp[i] = 2;
		Matrix m2(temp);
		Matrix m3(m2);
		std::cout << m1 << m2 << m3;
	}
	const void UnitTest::MatrixMethods()
	{
		Color_White
		std::cout << "\nMatrix Methods Test:" << std::endl;
		Matrix m1;
		float temp[16];
		for (int i = 0; i < 16; i++)
			if (i % 2)
				temp[i] = 2;
			else
				temp[i] = 4;
		Matrix m2(temp);
		Color_Yellow
		std::cout << "Matrix m1: " << m1;
		std::cout << "Matrix m2: " << m2;
		m1.SetTranslation(Vector3().Right());
		Color_Green
			std::cout << "SetTranslation (m1): ";
		Color_Cyan
			std::cout << m1;
		m2.Transpose();
		Color_Green
			std::cout << "Transpose (m2): ";
		Color_Cyan
			std::cout << m2;

	}
	const void UnitTest::MatrixStaticMethods()
	{
		Color_White
		std::cout << "\nMatrix Static Methods Test:" << std::endl;
		Color_Green
			std::cout << "MatrixIdentity: ";
		Color_Cyan
			std::cout << Matrix::Identity();
		Color_Green
			std::cout << "CreateTranslationMatrix: ";
		Color_Cyan
			std::cout << Matrix::CreateTranslationMatrix(Vector3(2, 1, 4));
		Color_Green
			std::cout << "CreateScaleMatrix: ";
		Color_Cyan
			std::cout << Matrix::CreateScaleMatrix(Vector3(1, 2, 5));
		Color_Green
			std::cout << "CreateTransformMatrix: ";
		//Color_Cyan
		//	std::cout << Matrix::CreateTransformMatrix(Vector3(4, 2, 1), Vector3(3, 1, 6), Quaternion(0.7071068, 0.7071068, 0, 0), false);
	}
	const void UnitTest::MatrixGetters()
	{
		Color_White
		std::cout << "\nMatrix Getters Test:" << std::endl;
		Color_Yellow
		float temp[16];
		temp[0] = 5;
		temp[1] = 6;
		temp[2] = 7;
		temp[3] = 0;
		temp[4] = 12;
		temp[5] = 1;
		temp[6] = 3;
		temp[7] = 9;
		temp[8] = 14;
		temp[9] = 19;
		temp[10] = 8;
		temp[11] = 3;
		temp[12] = 2;
		temp[13] = 7;
		temp[14] = 24;
		temp[15] = 0;
		Matrix m1(temp);
		std::cout << "Base Matrix: " << m1;
		Color_Green
			std::cout << "Determinant: ";
		Color_Cyan
			std::cout << m1.GetDeterminant() << std::endl;
		Color_Green
			std::cout << "Comatrix: ";
		Color_Cyan
			std::cout << m1.GetComatrix();
		Color_Green
			std::cout << "InverseMatrix: ";
		Color_Cyan
			std::cout << m1.GetInverseMatrix();
	}
	const void UnitTest::MatrixOperators()
	{
		Color_White
		std::cout << "\nMatrix Operators Test:" << std::endl;
		float temp1[16];
		for (int i = 0; i < 16; i++)
			if (i % 2)
				temp1[i] = 2;
			else
				temp1[i] = 4;
		Matrix m1(temp1);
		float temp2[16];
		for (int i = 0; i < 16; i++)
			if (i % 2)
				temp2[i] = 1;
			else
				temp2[i] = 3;
		Matrix m2(temp2);
		Color_Yellow
		std::cout << "Matrix m1: " << m1;
		std::cout << "Matrix m2: " << m2;
		Color_Green
			std::cout << "Matrix*float: ";
		Color_Cyan
			std::cout << m1 * 2;
		Color_Green
			std::cout << "Matrix*Matrix: ";
		Color_Cyan
			std::cout << m1 * m2;
		Color_Green
			std::cout << "Matrix*Vector3: ";
		Color_Cyan
			std::cout << m1 * Vector3(2, 1, 6);
		Color_Green
			std::cout << "Matrix*Vector4: ";
		Color_Cyan
			std::cout << m2 * Vector4(3, 7, 9, 1);
	}


	/* Quaternion */

	const void UnitTest::QuaternionAllTest()
	{
		QuaternionConstructors();
		QuaternionMethods();
		QuaternionStaticMethods();
		QuaternionGetters();
		QuaternionOperators();
	}
	const void UnitTest::QuaternionConstructors()
	{
		Out::ChangeColor(Out::MAGENTA);
		std::cout << "Quaternion(w, x, y ,z)\n\n";
		Color_White
		std::cout << "\nQuaternion Constructors Test:" << std::endl;
		Color_Cyan
			Quaternion q1;
		Quaternion q2(1, 2, 3, 4);
		Quaternion q3(1.0f, Vector3(7, 8, 9));
		Quaternion q4(Vector4(4, 3, 2, 1));
		std::cout << q1 << q2 << q3 << q4;
	}
	const void UnitTest::QuaternionMethods()
	{
		Color_White
		std::cout << "\nQuaternion Methods Test:" << std::endl;
		Quaternion q1(1, 5, 9, 4);
		Quaternion q2(1, 7, 28, 0.12f);
		Quaternion q3(10, 42, 3, 0);
		Color_Yellow
		std::cout << "Quaternion q1:\t\t\t" << q1;
		std::cout << "Quaternion q2:\t\t\t" << q2;
		std::cout << "Quaternion q3:\t\t\t" << q3;
		float temp = q1.DotProduct(q2);
		Color_Green
			std::cout << "DotProduct (q1,q2):\t\t";
		Color_Cyan
			std::cout << temp;
		Color_Green
			std::cout << "\nConjugate (q1):\t\t\t";
		Color_Cyan
			std::cout << q1.Conjugate();
		q3.Normalize();
		Color_Green
			std::cout << "Normalize (q3):\t\t\t";
		Color_Cyan
			std::cout << q3;
		q2.CreateRotationMatrix();
		Color_Green
			std::cout << "CreateRotationMatrix (q2):\t";
		Color_Cyan
			std::cout << q2.s_rotationMatrix;
	}
	const void UnitTest::QuaternionStaticMethods()
	{
		Color_White
		std::cout << "\nQuaternion Static Methods Test:" << std::endl;
		Color_Yellow
		Quaternion q1(11, 2.3f, 56, 7);
		Quaternion q2(0, 98, 63, 1.3f);
		Vector3 v(5, 6, 12);
		std::cout << "Quaternion q1:\t\t\t" << q1;
		std::cout << "Quaternion q2:\t\t\t" << q2;
		std::cout << "Vector v:\t\t\t" << v;
		Color_Green
			std::cout << "CreateQuaternionFromAngle:\t";
		Color_Cyan
			std::cout << Quaternion::CreateQuaternionFromAngle(90, Vector3(1, 0.5f, 0.25f));
		Color_Green
			std::cout << "Lerp (q1,q2,0.2f):\t\t";
		Color_Cyan
			std::cout << Quaternion::Lerp(q1, q2, 0.2f);
		Color_Green
			std::cout << "Slerp (q1,q2,0.2f):\t\t";
		Color_Cyan
			std::cout << Quaternion::Slerp(q1, q2, 0.2f);
		Color_Green
			std::cout << "I, J and K functions:\n";
		Out::ChangeColor(Out::GREEN);
		std::cout << "|->\tFor I(30):\t\t";
		Color_Cyan
		std::cout << Quaternion::I(30);
		Out::ChangeColor(Out::GREEN);
		std::cout << "|->\tFor J(60):\t\t";
		Color_Cyan
		std::cout << Quaternion::J(60);
		Out::ChangeColor(Out::GREEN);
		std::cout << "|->\tFor K(90):\t\t";
		Color_Cyan
		std::cout << Quaternion::K(90);
		Color_Green
			std::cout << "Euler (v):\t\t\t";
		Color_Cyan
			std::cout << Quaternion::Euler(v);
		Color_Green
			std::cout << "LookRotation (v):\t\t";
		Color_Cyan
			std::cout << Quaternion::LookRotation(v);
		Color_Green
			std::cout << "Angle (q1, q2):\t\t\t";
		Color_Cyan
			std::cout << Quaternion::Angle(q1, q2) << std::endl;
		Color_Green
			std::cout << "Inverse (q1):\t\t\t";
		Color_Cyan
			std::cout << Quaternion::Inverse(q1);
	}
	const void UnitTest::QuaternionGetters()
	{
		Color_White
		std::cout << "\nQuaternion Getters Test:" << std::endl;
		Color_Yellow
		Quaternion q1(6.8f, 56, 41, 11);
		std::cout << "Base Quaternion:\t" << q1;
		Color_Green
			std::cout << "Real:\t\t\t";
		Color_Cyan
			std::cout << q1.GetReal() << std::endl;
		Color_Green
			std::cout << "Imaginary:\t\t";
		Color_Cyan
			std::cout << q1.GetImaginary();
		Color_Green
			std::cout << "Magnitude:\t\t";
		Color_Cyan
			std::cout << q1.GetMagnitude() << std::endl;
		Color_Green
			std::cout << "Normalized:\t\t";
		Color_Cyan
			std::cout << q1.GetNormalized();
		Color_Green
			std::cout << "Inverse:\t\t";
		Color_Cyan
			std::cout << q1.GetInverse();
		Color_Green
			std::cout << "GetEulerAngles:\t\t";
		Color_Cyan
			std::cout << q1.GetEulerAngles();
		Color_Green
			std::cout << "Rotation Matrix:\t";
		Color_Cyan
			q1.CreateRotationMatrix();
		std::cout << q1.GetRotationMatrix();
	}
	const void UnitTest::QuaternionOperators()
	{
		Color_White
		std::cout << "\nQuaternion Operators Test:" << std::endl;
		Quaternion q1(1, 2, 3, 4);
		Quaternion q2(4, 1, 5, 2);
		Vector3 v1(4, 18, 9);
		Color_Yellow
		std::cout << "Quaternion q1:\t\t\t\t" << q1;
		std::cout << "Quaternion q2:\t\t\t\t" << q2;
		std::cout << "Vector3 v1:\t\t\t\t" << v1;
		Color_Green
			std::cout << "Quaternion*Vector3 (q1*v1):\t\t";
		Color_Cyan
			std::cout << q1*v1;
		Color_Green
			std::cout << "Quaternion*Quaternion (q1*q2):\t\t";
		Color_Cyan
			std::cout << q1*q2;
		Color_Green
			std::cout << "Quaternion*float (q1*2):\t\t";
		Color_Cyan
			std::cout << q1 * 2;
		Color_Green
			std::cout << "Quaternion/float (q2/2):\t\t";
		Color_Cyan
			std::cout << q2 / 2;
		Color_Green
			std::cout << "Quaternion+Quaternion (q1+q2):\t\t";
		Color_Cyan
			std::cout << q1 + q2;
		Color_Green
			std::cout << "Opposite (q2):\t\t\t\t";
		Color_Cyan
			std::cout << -q2;
		q1 *= q2;
		Color_Green
			std::cout << "Quaterion*=Quaternion (q1*=q2):\t\t";
		Color_Cyan
			std::cout << q1;
		q1 += q2;
		Color_Green
			std::cout << "Quaterion+=Quaternion (q1+=q2):\t\t";
		Color_Cyan
			std::cout << q1;
		q1 -= q2;
		Color_Green
			std::cout << "Quaterion-=Quaternion (q1-=q2):\t\t";
		Color_Cyan
			std::cout << q1;
	}
}

namespace Log
{
	/* Color Methods */

	const void Out::Separate(bool _jump, std::string _str)
	{
		Out::ChangeColor(Out::RED);
		if (!_jump)
		{
			std::cout << "///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
			std::cout << "\t\t\t\t\t\t\t" << _str << "\n" << std::endl;
		}
		else
		{
			std::cout << "\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
			std::cout << "\t\t\t\t\t\t\t" << _str << "\n" << std::endl;
		}
		Out::ChangeColor(Out::WHITE);
	}
	const void Out::ChangeColor(Color _c)
	{
		HANDLE hconsole;
		hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hconsole, _c);
	}
}