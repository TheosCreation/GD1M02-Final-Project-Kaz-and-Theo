#include "Calculator.h"

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

int Calculator::GetDeterminant(Matrix _MatrixA)
{

	
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			for (int k = i + 1; k < 4; k++) {
				_MatrixA.m_MatrixArray[j][k] = _MatrixA.m_MatrixArray[j][k] * _MatrixA.m_MatrixArray[i][i] - _MatrixA.m_MatrixArray[j][i] * _MatrixA.m_MatrixArray[i][k];
				if (i != 0) {
					_MatrixA.m_MatrixArray[j][k] /= _MatrixA.m_MatrixArray[i - 1][i - 1];
				}
			}
		}
	}
	return _MatrixA.m_MatrixArray[3][3];
}

Matrix Calculator::GetTranspose(Matrix _MatrixA)
{
	Matrix ReturnedMatrix;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ReturnedMatrix.ReplaceMatrixVal(i, j, _MatrixA.m_MatrixArray[j][i]);
		}
	}

	return ReturnedMatrix;
}

Matrix Calculator::GetInverse(Matrix _MatrixA)
{

	return Matrix();
}

Matrix Calculator::MultiplyByScalar(Matrix _MatrixA, int _Scalar)
{
	return Matrix();
}

Matrix Calculator::MatrixAdd(Matrix _MatrixA, Matrix _MatrixB)
{
	return Matrix();
}

Matrix Calculator::MatrixSubtract(Matrix _MatrixA, Matrix _MatrixB)
{
	return Matrix();
}

Matrix Calculator::MatrixMultiply(Matrix _MatrixA, Matrix _MatrixB)
{
	return Matrix();
}

Matrix Calculator::MatrixMultiplyReverse(Matrix _MatrixB, Matrix _MatrixA)
{
	return Matrix();
}

Matrix Calculator::GenerateIdentity()
{
	return Matrix();
}
