#include "Matrix.h"
#include "Quaternion.h"

namespace CMath
{
	/* Constructors */

	Matrix::Matrix()
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				s_matrix[(i * 4) + j] = 0;
		s_matrix[0] = s_matrix[5] = s_matrix[10] = s_matrix[15] = 1;
	}
	Matrix::Matrix(const Matrix& _matrix)
	{
		for (int i = 0; i < 16; i++)
			s_matrix[i] = _matrix[i];
	}
	Matrix::Matrix(const float(&_array)[16])
	{
		for (int i = 0; i < 16; i++)
			s_matrix[i] = _array[i];
	}


	/* Methods */

	void Matrix::SetTranslation(const Vector3& _vector)
	{
		s_matrix[3] = _vector.s_x;
		s_matrix[7] = _vector.s_y;
		s_matrix[11] = _vector.s_z;
	}
	void Matrix::Transpose()
	{
		Matrix transpose = *this;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				s_matrix[j * 4 + i] = transpose[i * 4 + j];
	}
	float Matrix::GetDeterminant() const
	{
		float det = s_matrix[0] * s_matrix[5] * s_matrix[10] * s_matrix[15] + s_matrix[0] * s_matrix[6] * s_matrix[11] * s_matrix[13] + s_matrix[0] * s_matrix[7] * s_matrix[9] * s_matrix[14]
			+ s_matrix[1] * s_matrix[4] * s_matrix[11] * s_matrix[14] + s_matrix[1] * s_matrix[6] * s_matrix[8] * s_matrix[15] + s_matrix[1] * s_matrix[7] * s_matrix[10] * s_matrix[12]
			+ s_matrix[2] * s_matrix[4] * s_matrix[9] * s_matrix[15] + s_matrix[2] * s_matrix[5] * s_matrix[11] * s_matrix[12] + s_matrix[2] * s_matrix[7] * s_matrix[8] * s_matrix[13]
			+ s_matrix[3] * s_matrix[4] * s_matrix[10] * s_matrix[13] + s_matrix[3] * s_matrix[5] * s_matrix[8] * s_matrix[14] + s_matrix[3] * s_matrix[6] * s_matrix[9] * s_matrix[12]
			- s_matrix[0] * s_matrix[5] * s_matrix[11] * s_matrix[14] - s_matrix[0] * s_matrix[6] * s_matrix[9] * s_matrix[15] - s_matrix[0] * s_matrix[7] * s_matrix[10] * s_matrix[13]
			- s_matrix[1] * s_matrix[4] * s_matrix[10] * s_matrix[15] - s_matrix[1] * s_matrix[6] * s_matrix[11] * s_matrix[12] - s_matrix[1] * s_matrix[7] * s_matrix[8] * s_matrix[14]
			- s_matrix[2] * s_matrix[4] * s_matrix[11] * s_matrix[13] - s_matrix[2] * s_matrix[5] * s_matrix[8] * s_matrix[15] - s_matrix[2] * s_matrix[7] * s_matrix[9] * s_matrix[12]
			- s_matrix[3] * s_matrix[4] * s_matrix[9] * s_matrix[14] - s_matrix[3] * s_matrix[5] * s_matrix[10] * s_matrix[12] - s_matrix[3] * s_matrix[6] * s_matrix[8] * s_matrix[13];

		return det;
	}
	Matrix Matrix::GetComatrix() const
	{
		Matrix temp;

		temp.s_matrix[0] = s_matrix[5] * s_matrix[10] * s_matrix[15] + s_matrix[6] * s_matrix[11] * s_matrix[13] + s_matrix[7] * s_matrix[9] * s_matrix[14] - s_matrix[5] * s_matrix[11] * s_matrix[14] - s_matrix[6] * s_matrix[9] * s_matrix[15] - s_matrix[7] * s_matrix[10] * s_matrix[13];
		temp.s_matrix[1] = s_matrix[4] * s_matrix[11] * s_matrix[14] + s_matrix[6] * s_matrix[8] * s_matrix[15] + s_matrix[7] * s_matrix[10] * s_matrix[12] - s_matrix[4] * s_matrix[10] * s_matrix[15] - s_matrix[6] * s_matrix[11] * s_matrix[12] - s_matrix[7] * s_matrix[8] * s_matrix[14];
		temp.s_matrix[2] = s_matrix[4] * s_matrix[9] * s_matrix[15] + s_matrix[5] * s_matrix[11] * s_matrix[12] + s_matrix[7] * s_matrix[8] * s_matrix[13] - s_matrix[4] * s_matrix[11] * s_matrix[13] - s_matrix[5] * s_matrix[8] * s_matrix[15] - s_matrix[7] * s_matrix[9] * s_matrix[12];
		temp.s_matrix[3] = s_matrix[4] * s_matrix[10] * s_matrix[13] + s_matrix[5] * s_matrix[8] * s_matrix[14] + s_matrix[6] * s_matrix[9] * s_matrix[12] - s_matrix[4] * s_matrix[9] * s_matrix[14] - s_matrix[5] * s_matrix[10] * s_matrix[12] - s_matrix[6] * s_matrix[8] * s_matrix[13];

		temp.s_matrix[4] = s_matrix[1] * s_matrix[11] * s_matrix[14] + s_matrix[2] * s_matrix[9] * s_matrix[15] + s_matrix[3] * s_matrix[10] * s_matrix[13] - s_matrix[1] * s_matrix[10] * s_matrix[15] - s_matrix[2] * s_matrix[11] * s_matrix[13] - s_matrix[3] * s_matrix[9] * s_matrix[13];
		temp.s_matrix[5] = s_matrix[0] * s_matrix[10] * s_matrix[15] + s_matrix[2] * s_matrix[11] * s_matrix[12] + s_matrix[3] * s_matrix[8] * s_matrix[14] - s_matrix[0] * s_matrix[11] * s_matrix[14] - s_matrix[2] * s_matrix[8] * s_matrix[15] - s_matrix[3] * s_matrix[10] * s_matrix[12];
		temp.s_matrix[6] = s_matrix[0] * s_matrix[11] * s_matrix[13] + s_matrix[1] * s_matrix[8] * s_matrix[15] + s_matrix[3] * s_matrix[9] * s_matrix[12] - s_matrix[0] * s_matrix[9] * s_matrix[15] - s_matrix[1] * s_matrix[11] * s_matrix[12] - s_matrix[3] * s_matrix[8] * s_matrix[13];
		temp.s_matrix[7] = s_matrix[0] * s_matrix[9] * s_matrix[14] + s_matrix[1] * s_matrix[10] * s_matrix[12] + s_matrix[2] * s_matrix[8] * s_matrix[13] - s_matrix[0] * s_matrix[10] * s_matrix[13] - s_matrix[1] * s_matrix[8] * s_matrix[14] - s_matrix[2] * s_matrix[9] * s_matrix[12];

		temp.s_matrix[8] = s_matrix[1] * s_matrix[6] * s_matrix[15] + s_matrix[2] * s_matrix[7] * s_matrix[13] + s_matrix[3] * s_matrix[5] * s_matrix[14] - s_matrix[1] * s_matrix[7] * s_matrix[14] - s_matrix[2] * s_matrix[5] * s_matrix[15] - s_matrix[3] * s_matrix[6] * s_matrix[13];
		temp.s_matrix[9] = s_matrix[0] * s_matrix[7] * s_matrix[14] + s_matrix[2] * s_matrix[4] * s_matrix[15] + s_matrix[3] * s_matrix[6] * s_matrix[12] - s_matrix[0] * s_matrix[6] * s_matrix[15] - s_matrix[2] * s_matrix[7] * s_matrix[12] - s_matrix[3] * s_matrix[4] * s_matrix[14];
		temp.s_matrix[10] = s_matrix[0] * s_matrix[5] * s_matrix[15] + s_matrix[1] * s_matrix[7] * s_matrix[12] + s_matrix[3] * s_matrix[4] * s_matrix[13] - s_matrix[0] * s_matrix[7] * s_matrix[13] - s_matrix[1] * s_matrix[4] * s_matrix[15] - s_matrix[3] * s_matrix[5] * s_matrix[12];
		temp.s_matrix[11] = s_matrix[0] * s_matrix[6] * s_matrix[13] + s_matrix[1] * s_matrix[4] * s_matrix[14] + s_matrix[2] * s_matrix[5] * s_matrix[12] - s_matrix[0] * s_matrix[5] * s_matrix[14] - s_matrix[1] * s_matrix[6] * s_matrix[12] - s_matrix[2] * s_matrix[4] * s_matrix[13];

		temp.s_matrix[12] = s_matrix[1] * s_matrix[7] * s_matrix[10] + s_matrix[2] * s_matrix[5] * s_matrix[11] + s_matrix[3] * s_matrix[6] * s_matrix[9] - s_matrix[1] * s_matrix[6] * s_matrix[11] - s_matrix[2] * s_matrix[7] * s_matrix[9] - s_matrix[3] * s_matrix[5] * s_matrix[10];
		temp.s_matrix[13] = s_matrix[0] * s_matrix[6] * s_matrix[11] + s_matrix[2] * s_matrix[7] * s_matrix[8] + s_matrix[3] * s_matrix[4] * s_matrix[10] - s_matrix[0] * s_matrix[7] * s_matrix[10] - s_matrix[2] * s_matrix[4] * s_matrix[11] - s_matrix[3] * s_matrix[6] * s_matrix[8];
		temp.s_matrix[14] = s_matrix[0] * s_matrix[7] * s_matrix[9] + s_matrix[1] * s_matrix[4] * s_matrix[11] + s_matrix[3] * s_matrix[5] * s_matrix[8] - s_matrix[0] * s_matrix[5] * s_matrix[11] - s_matrix[1] * s_matrix[7] * s_matrix[8] - s_matrix[3] * s_matrix[4] * s_matrix[9];
		temp.s_matrix[15] = s_matrix[0] * s_matrix[5] * s_matrix[10] + s_matrix[1] * s_matrix[6] * s_matrix[8] + s_matrix[2] * s_matrix[4] * s_matrix[9] - s_matrix[0] * s_matrix[6] * s_matrix[9] - s_matrix[1] * s_matrix[4] * s_matrix[10] - s_matrix[2] * s_matrix[5] * s_matrix[8];

		return temp;
	}
	Matrix Matrix::GetInverseMatrix() const
	{
		float determinant = GetDeterminant();

		if (determinant == 0)
		{
			std::cout << "Cannot create the inverse of this Matrix" << std::endl;
			return *this;
		}

		Matrix comatrix = *this;

		comatrix.s_matrix[0] = s_matrix[5] * s_matrix[10] * s_matrix[15] + s_matrix[6] * s_matrix[11] * s_matrix[13] + s_matrix[7] * s_matrix[9] * s_matrix[14] - s_matrix[5] * s_matrix[11] * s_matrix[14] - s_matrix[6] * s_matrix[9] * s_matrix[15] - s_matrix[7] * s_matrix[10] * s_matrix[13];
		comatrix.s_matrix[1] = s_matrix[1] * s_matrix[11] * s_matrix[14] + s_matrix[2] * s_matrix[9] * s_matrix[15] + s_matrix[3] * s_matrix[10] * s_matrix[13] - s_matrix[1] * s_matrix[10] * s_matrix[15] - s_matrix[2] * s_matrix[11] * s_matrix[13] - s_matrix[3] * s_matrix[9] * s_matrix[13];
		comatrix.s_matrix[2] = s_matrix[1] * s_matrix[6] * s_matrix[15] + s_matrix[2] * s_matrix[7] * s_matrix[13] + s_matrix[3] * s_matrix[5] * s_matrix[14] - s_matrix[1] * s_matrix[7] * s_matrix[14] - s_matrix[2] * s_matrix[5] * s_matrix[15] - s_matrix[3] * s_matrix[6] * s_matrix[13];
		comatrix.s_matrix[3] = s_matrix[1] * s_matrix[7] * s_matrix[10] + s_matrix[2] * s_matrix[5] * s_matrix[11] + s_matrix[3] * s_matrix[6] * s_matrix[9] - s_matrix[1] * s_matrix[6] * s_matrix[11] - s_matrix[2] * s_matrix[7] * s_matrix[9] - s_matrix[3] * s_matrix[5] * s_matrix[10];

		comatrix.s_matrix[4] = s_matrix[4] * s_matrix[11] * s_matrix[14] + s_matrix[6] * s_matrix[8] * s_matrix[15] + s_matrix[7] * s_matrix[10] * s_matrix[12] - s_matrix[4] * s_matrix[10] * s_matrix[15] - s_matrix[6] * s_matrix[11] * s_matrix[12] - s_matrix[7] * s_matrix[8] * s_matrix[14];
		comatrix.s_matrix[5] = s_matrix[0] * s_matrix[10] * s_matrix[15] + s_matrix[2] * s_matrix[11] * s_matrix[12] + s_matrix[3] * s_matrix[8] * s_matrix[14] - s_matrix[0] * s_matrix[11] * s_matrix[14] - s_matrix[2] * s_matrix[8] * s_matrix[15] - s_matrix[3] * s_matrix[10] * s_matrix[12];
		comatrix.s_matrix[6] = s_matrix[0] * s_matrix[7] * s_matrix[14] + s_matrix[2] * s_matrix[4] * s_matrix[15] + s_matrix[3] * s_matrix[6] * s_matrix[12] - s_matrix[0] * s_matrix[6] * s_matrix[15] - s_matrix[2] * s_matrix[7] * s_matrix[12] - s_matrix[3] * s_matrix[4] * s_matrix[14];
		comatrix.s_matrix[7] = s_matrix[0] * s_matrix[6] * s_matrix[11] + s_matrix[2] * s_matrix[7] * s_matrix[8] + s_matrix[3] * s_matrix[4] * s_matrix[10] - s_matrix[0] * s_matrix[7] * s_matrix[10] - s_matrix[2] * s_matrix[4] * s_matrix[11] - s_matrix[3] * s_matrix[6] * s_matrix[8];

		comatrix.s_matrix[8] = s_matrix[4] * s_matrix[9] * s_matrix[15] + s_matrix[5] * s_matrix[11] * s_matrix[12] + s_matrix[7] * s_matrix[8] * s_matrix[13] - s_matrix[4] * s_matrix[11] * s_matrix[13] - s_matrix[5] * s_matrix[8] * s_matrix[15] - s_matrix[7] * s_matrix[9] * s_matrix[12];
		comatrix.s_matrix[9] = s_matrix[0] * s_matrix[11] * s_matrix[13] + s_matrix[1] * s_matrix[8] * s_matrix[15] + s_matrix[3] * s_matrix[9] * s_matrix[12] - s_matrix[0] * s_matrix[9] * s_matrix[15] - s_matrix[1] * s_matrix[11] * s_matrix[12] - s_matrix[3] * s_matrix[8] * s_matrix[13];
		comatrix.s_matrix[10] = s_matrix[0] * s_matrix[5] * s_matrix[15] + s_matrix[1] * s_matrix[7] * s_matrix[12] + s_matrix[3] * s_matrix[4] * s_matrix[13] - s_matrix[0] * s_matrix[7] * s_matrix[13] - s_matrix[1] * s_matrix[4] * s_matrix[15] - s_matrix[3] * s_matrix[5] * s_matrix[12];
		comatrix.s_matrix[11] = s_matrix[0] * s_matrix[7] * s_matrix[9] + s_matrix[1] * s_matrix[4] * s_matrix[11] + s_matrix[3] * s_matrix[5] * s_matrix[8] - s_matrix[0] * s_matrix[5] * s_matrix[11] - s_matrix[1] * s_matrix[7] * s_matrix[8] - s_matrix[3] * s_matrix[4] * s_matrix[9];

		comatrix.s_matrix[12] = s_matrix[4] * s_matrix[10] * s_matrix[13] + s_matrix[5] * s_matrix[8] * s_matrix[14] + s_matrix[6] * s_matrix[9] * s_matrix[12] - s_matrix[4] * s_matrix[9] * s_matrix[14] - s_matrix[5] * s_matrix[10] * s_matrix[12] - s_matrix[6] * s_matrix[8] * s_matrix[13];
		comatrix.s_matrix[13] = s_matrix[0] * s_matrix[9] * s_matrix[14] + s_matrix[1] * s_matrix[10] * s_matrix[12] + s_matrix[2] * s_matrix[8] * s_matrix[13] - s_matrix[0] * s_matrix[10] * s_matrix[13] - s_matrix[1] * s_matrix[8] * s_matrix[14] - s_matrix[2] * s_matrix[9] * s_matrix[12];
		comatrix.s_matrix[14] = s_matrix[0] * s_matrix[6] * s_matrix[13] + s_matrix[1] * s_matrix[4] * s_matrix[14] + s_matrix[2] * s_matrix[5] * s_matrix[12] - s_matrix[0] * s_matrix[5] * s_matrix[14] - s_matrix[1] * s_matrix[6] * s_matrix[12] - s_matrix[2] * s_matrix[4] * s_matrix[13];
		comatrix.s_matrix[15] = s_matrix[0] * s_matrix[5] * s_matrix[10] + s_matrix[1] * s_matrix[6] * s_matrix[8] + s_matrix[2] * s_matrix[4] * s_matrix[9] - s_matrix[0] * s_matrix[6] * s_matrix[9] - s_matrix[1] * s_matrix[4] * s_matrix[10] - s_matrix[2] * s_matrix[5] * s_matrix[8];

		Matrix inverseMatrix = comatrix * (1 / determinant);

		return inverseMatrix;
	}


	/* Static Method */

	Matrix Matrix::Identity()
	{
		Matrix identity;
		return identity;
	}
	Matrix Matrix::CreateTranslationMatrix(const Vector3& _vector)
	{
		Matrix temp;
		temp[3] = _vector.s_x;
		temp[7] = _vector.s_y;
		temp[11] = _vector.s_z;

		return temp;
	}
	Matrix Matrix::CreateScaleMatrix(const Vector3& _vector)
	{
		Matrix temp;
		temp[0] = _vector.s_x;
		temp[5] = _vector.s_y;
		temp[10] = _vector.s_z;
		return temp;
	}
	Matrix Matrix::CreateRotationMatrix(const Vector3& _vec)
	{
		return CreateXRotationMatrix(_vec.s_x) * CreateYRotationMatrix(_vec.s_y) * CreateZRotationMatrix(_vec.s_z);
	}
	Matrix Matrix::CreateXRotationMatrix(float angle)
	{
		float c = cosf(angle * M_RAD);
		float s{ 0 };
		s = sinf(angle * M_RAD);

		Matrix matBuffer;
		matBuffer.s_matrix[5] = c;
		matBuffer.s_matrix[6] = -s;
		matBuffer.s_matrix[9] = s;
		matBuffer.s_matrix[10] = c;

		return matBuffer;
	}
	Matrix Matrix::CreateYRotationMatrix(float angle)
	{
		float c = cosf(angle * M_RAD);
		float s = sinf(angle * M_RAD);

		Matrix matBuffer;
		matBuffer.s_matrix[0] = c;
		matBuffer.s_matrix[2] = -s;
		matBuffer.s_matrix[8] = s;
		matBuffer.s_matrix[10] = c;

		return matBuffer;
	}
	Matrix Matrix::CreateZRotationMatrix(float angle)
	{
		float c{ 0 };
		c = cosf(angle * M_RAD);
		float s{ 0 };
		s = sinf(angle * M_RAD);

		Matrix matBuffer;
		matBuffer.s_matrix[0] = c;
		matBuffer.s_matrix[1] = -s;
		matBuffer.s_matrix[4] = s;
		matBuffer.s_matrix[5] = c;

		return matBuffer;
	}
	Matrix Matrix::CreateTransformMatrix(const Vector3& _location, const Vector3& _scale, Quaternion& _rotation, bool _transpose)
	{
		Matrix result;

		Matrix S = Matrix::CreateScaleMatrix(_scale);
		_rotation.CreateRotationMatrix();
		Matrix R = _rotation.s_rotationMatrix;

		result = R * S;

		result[3] = _location.s_x;
		result[7] = _location.s_y;
		result[11] = _location.s_z;


		if (_transpose)
			result.Transpose();

		return result;
	}
	Matrix Matrix::CreateTransformMatrix(const Vector3& _location, const Vector3& _scale, Vector3& _rotation, bool _transpose)
	{
		Matrix result;

		Matrix T = Matrix::CreateTranslationMatrix(_location);
		Matrix S = Matrix::CreateScaleMatrix(_scale);
		Matrix R = Matrix::CreateRotationMatrix(_rotation);

		result = T * R * S;
		if (_transpose)
			result.Transpose();

		return result;
	}


	/* Operators */

	float& Matrix::operator[](const int _number)
	{
		return s_matrix[_number];
	}
	float Matrix::operator[](const int _number) const
	{
		return s_matrix[_number];
	}

	int Matrix::operator!=(const Matrix& _matrix) const
	{
		bool same = true;
		for (int i = 0; i < 16; i++)
		{
			if (s_matrix[i] != _matrix[i])
				same = false;
		}

		if (!same)
			return 1;
		else
			return 0;
	}
	int Matrix::operator==(const Matrix& _matrix) const
	{
		bool same = true;
		for (int i = 0; i < 16; i++)
		{
			if (s_matrix[i] != _matrix[i])
				same = false;
		}

		if (same)
			return 1;
		else
			return 0;
	}
	Matrix Matrix::operator*(const float _value)
	{
		Matrix result = *this;

		result.s_matrix[0] *= _value;
		result.s_matrix[1] *= _value;
		result.s_matrix[2] *= _value;
		result.s_matrix[3] *= _value;
		result.s_matrix[4] *= _value;
		result.s_matrix[5] *= _value;
		result.s_matrix[6] *= _value;
		result.s_matrix[7] *= _value;
		result.s_matrix[8] *= _value;
		result.s_matrix[9] *= _value;
		result.s_matrix[10] *= _value;
		result.s_matrix[11] *= _value;
		result.s_matrix[12] *= _value;
		result.s_matrix[13] *= _value;
		result.s_matrix[14] *= _value;
		result.s_matrix[15] *= _value;

		return result;
	}
	Matrix Matrix::operator*(const Matrix& _matrix)
	{
		Matrix result;

		result.s_matrix[0] = s_matrix[0] * _matrix.s_matrix[0] + s_matrix[1] * _matrix.s_matrix[4] + s_matrix[2] * _matrix.s_matrix[8] + s_matrix[3] * _matrix.s_matrix[12];
		result.s_matrix[1] = s_matrix[0] * _matrix.s_matrix[1] + s_matrix[1] * _matrix.s_matrix[5] + s_matrix[2] * _matrix.s_matrix[9] + s_matrix[3] * _matrix.s_matrix[13];
		result.s_matrix[2] = s_matrix[0] * _matrix.s_matrix[2] + s_matrix[1] * _matrix.s_matrix[6] + s_matrix[2] * _matrix.s_matrix[10] + s_matrix[3] * _matrix.s_matrix[14];
		result.s_matrix[3] = s_matrix[0] * _matrix.s_matrix[3] + s_matrix[1] * _matrix.s_matrix[7] + s_matrix[2] * _matrix.s_matrix[11] + s_matrix[3] * _matrix.s_matrix[15];

		result.s_matrix[4] = s_matrix[4] * _matrix.s_matrix[0] + s_matrix[5] * _matrix.s_matrix[4] + s_matrix[6] * _matrix.s_matrix[8] + s_matrix[7] * _matrix.s_matrix[12];
		result.s_matrix[5] = s_matrix[4] * _matrix.s_matrix[1] + s_matrix[5] * _matrix.s_matrix[5] + s_matrix[6] * _matrix.s_matrix[9] + s_matrix[7] * _matrix.s_matrix[13];
		result.s_matrix[6] = s_matrix[4] * _matrix.s_matrix[2] + s_matrix[5] * _matrix.s_matrix[6] + s_matrix[6] * _matrix.s_matrix[10] + s_matrix[7] * _matrix.s_matrix[14];
		result.s_matrix[7] = s_matrix[4] * _matrix.s_matrix[3] + s_matrix[5] * _matrix.s_matrix[7] + s_matrix[6] * _matrix.s_matrix[11] + s_matrix[7] * _matrix.s_matrix[15];

		result.s_matrix[8] = s_matrix[8] * _matrix.s_matrix[0] + s_matrix[9] * _matrix.s_matrix[4] + s_matrix[10] * _matrix.s_matrix[8] + s_matrix[11] * _matrix.s_matrix[12];
		result.s_matrix[9] = s_matrix[8] * _matrix.s_matrix[1] + s_matrix[9] * _matrix.s_matrix[5] + s_matrix[10] * _matrix.s_matrix[9] + s_matrix[11] * _matrix.s_matrix[13];
		result.s_matrix[10] = s_matrix[8] * _matrix.s_matrix[2] + s_matrix[9] * _matrix.s_matrix[6] + s_matrix[10] * _matrix.s_matrix[10] + s_matrix[11] * _matrix.s_matrix[14];
		result.s_matrix[11] = s_matrix[8] * _matrix.s_matrix[3] + s_matrix[9] * _matrix.s_matrix[7] + s_matrix[10] * _matrix.s_matrix[11] + s_matrix[11] * _matrix.s_matrix[15];

		result.s_matrix[12] = s_matrix[12] * _matrix.s_matrix[0] + s_matrix[13] * _matrix.s_matrix[4] + s_matrix[14] * _matrix.s_matrix[8] + s_matrix[15] * _matrix.s_matrix[12];
		result.s_matrix[13] = s_matrix[12] * _matrix.s_matrix[1] + s_matrix[13] * _matrix.s_matrix[5] + s_matrix[14] * _matrix.s_matrix[9] + s_matrix[15] * _matrix.s_matrix[13];
		result.s_matrix[14] = s_matrix[12] * _matrix.s_matrix[2] + s_matrix[13] * _matrix.s_matrix[6] + s_matrix[14] * _matrix.s_matrix[10] + s_matrix[15] * _matrix.s_matrix[14];
		result.s_matrix[15] = s_matrix[12] * _matrix.s_matrix[3] + s_matrix[13] * _matrix.s_matrix[7] + s_matrix[14] * _matrix.s_matrix[11] + s_matrix[15] * _matrix.s_matrix[15];

		return result;
	}
	Vector3 Matrix::operator*(const Vector3& _vector)
	{
		Vector3 vecBuffer;
		float buffer = 0;

		for (int i = 0; i < 4; i++)
		{
			buffer = 0;
			for (int j = 0; j < 4; j++)
			{
				buffer += s_matrix[(i * 4) + j] * _vector.s_x;
				j++;
				buffer += s_matrix[(i * 4) + j] * _vector.s_y;
				j++;
				buffer += s_matrix[(i * 4) + j] * _vector.s_z;
				j++;
			}

			if (i == 0)
				vecBuffer.s_x = buffer;
			else if (i == 1)
				vecBuffer.s_y = buffer;
			else if (i == 2)
				vecBuffer.s_z = buffer;
		}
		return vecBuffer;
	}
	Vector4 Matrix::operator*(const Vector4& _vector)
	{
		Vector4 vecBuffer;
		float buffer = 0;

		for (int i = 0; i < 4; i++)
		{
			buffer = 0;
			for (int j = 0; j < 4; j++)
			{
				buffer += s_matrix[(i * 4) + j] * _vector.s_x;
				j++;
				buffer += s_matrix[(i * 4) + j] * _vector.s_y;
				j++;
				buffer += s_matrix[(i * 4) + j] * _vector.s_z;
				j++;
				buffer += s_matrix[(i * 4) + j] * _vector.s_w;
				j++;
			}

			if (i == 0)
				vecBuffer.s_x = buffer;
			else if (i == 1)
				vecBuffer.s_y = buffer;
			else if (i == 2)
				vecBuffer.s_z = buffer;
			else if (i == 3)
				vecBuffer.s_w = buffer;
		}
		return vecBuffer;
	}


	/* External Operators */

	std::ostream& operator<<(std::ostream& _outStream, const Matrix& _matrix)
	{
		return _outStream << "Matrix {\n" <<
			"\t\t\t\t" << _matrix[0] << "\t" << _matrix[1] << "\t" << _matrix[2] << "\t" << _matrix[3] << "\n" <<
			"\t\t\t\t" << _matrix[4] << "\t" << _matrix[5] << "\t" << _matrix[6] << "\t" << _matrix[7] << "\n" <<
			"\t\t\t\t" << _matrix[8] << "\t" << _matrix[9] << "\t" << _matrix[10] << "\t" << _matrix[11] << "\n" <<
			"\t\t\t\t" << _matrix[12] << "\t" << _matrix[13] << "\t" << _matrix[14] << "\t" << _matrix[15] << " }\n";
	}
}