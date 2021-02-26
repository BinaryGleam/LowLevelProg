#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "Vector4.h"

namespace CMath
{
	typedef class Quaternion Quaternion;

	struct Matrix
	{
		/* Variables */

		float s_matrix[16];


		/* Constructors */

		Matrix();
		Matrix(const Matrix& _matrix);
		Matrix(const float (&_array)[16]);


		/* Destructor */

		~Matrix() = default;


		/* Methods */

		void SetTranslation(const Vector3& _vector);
		void Transpose();


		/* Static Method */

		static Matrix Identity();
		static Matrix CreateTranslationMatrix(const Vector3& _vector);
		static Matrix CreateScaleMatrix(const Vector3& _vector);
		static Matrix CreateRotationMatrix(const Vector3& _vector);
		static Matrix CreateXRotationMatrix(float _angle);
		static Matrix CreateYRotationMatrix(float _angle);
		static Matrix CreateZRotationMatrix(float _angle);
		static Matrix CreateTransformMatrix(const Vector3& _location, const Vector3& _scale, Quaternion& _rotation, bool _transpose);
		static Matrix CreateTransformMatrix(const Vector3& _location, const Vector3& _scale, Vector3& _rotation, bool _transpose);


		/* Getters */

		float GetDeterminant() const;
		Matrix GetComatrix() const;
		Matrix GetInverseMatrix() const;


		/* Operators */

		float& operator[](const int _number);
		float operator[](const int _number) const;
		int operator!=(const Matrix& _matrix) const;
		int operator==(const Matrix& _matrix) const;
		Matrix operator*(const float _value);
		Matrix operator*(const Matrix& _matrix);
		Vector3 operator*(const Vector3& _vector);
		Vector4 operator*(const Vector4& _vector);
	};

	/* External Operators */

	std::ostream& operator<<(std::ostream& _outStream, const Matrix& _matrix);
}

#endif