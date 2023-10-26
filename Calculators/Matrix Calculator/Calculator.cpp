#include "Calculator.h"

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

float Calculator::GetDeterminant4x4(Matrix _MatrixA)
{
	float Determinant = 0;
	int sign = 1;
	Matrix TempMatrix;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				TempMatrix.m_MatrixArray[j][k] = _MatrixA.m_MatrixArray[(j + 1) % 4][(k + 1 + i) % 4];  // Note the change here
			}
		}

		float subDet = GetDeterminant3x3(TempMatrix);

		Determinant += sign * _MatrixA.m_MatrixArray[0][i] * subDet;
		sign = -sign;
	}

	return Determinant;
}
float Calculator::GetDeterminant3x3(Matrix _MatrixA)
{
	return _MatrixA.m_MatrixArray[0][0] * (_MatrixA.m_MatrixArray[1][1] * _MatrixA.m_MatrixArray[2][2] - _MatrixA.m_MatrixArray[1][2] * _MatrixA.m_MatrixArray[2][1]) -
		_MatrixA.m_MatrixArray[0][1] * (_MatrixA.m_MatrixArray[1][0] * _MatrixA.m_MatrixArray[2][2] - _MatrixA.m_MatrixArray[1][2] * _MatrixA.m_MatrixArray[2][0]) +
		_MatrixA.m_MatrixArray[0][2] * (_MatrixA.m_MatrixArray[1][0] * _MatrixA.m_MatrixArray[2][1] - _MatrixA.m_MatrixArray[1][1] * _MatrixA.m_MatrixArray[2][0]);
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

	float determinant = GetDeterminant4x4(_MatrixA);

	// Check if the determinant is zero (matrix is singular)
	if (determinant == 0) {
		// Handle the case when the matrix is not invertible
		return GenerateIdentity(4);
	}

	float inverseFactor = (1.0 / determinant);

	return GetTranspose(MultiplyByScalar(GetCofactor4x4(_MatrixA), inverseFactor));
}

Matrix Calculator::GetCofactor4x4(Matrix _MatrixA)
{
	Matrix cofactorMatrix;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// Create a 3x3 matrix by excluding the current row and column
			Matrix minor;
			int minorRow = 0, minorCol = 0;
			for (int row = 0; row < 4; row++) {
				for (int col = 0; col < 4; col++) {
					if (row != i && col != j) {
						minor.m_MatrixArray[minorRow][minorCol] = _MatrixA.m_MatrixArray[row][col];
						minorCol++;
						if (minorCol == 3) {
							minorCol = 0;
							minorRow++;
						}
					}
				}
			}

			// Calculate the determinant of the 3x3 matrix
			float det = GetDeterminant3x3(minor);

			// Calculate the cofactor
			cofactorMatrix.m_MatrixArray[i][j] = det * ((i + j) % 2 == 0 ? 1 : -1);
		}
	}

	return cofactorMatrix;
}


Matrix Calculator::MultiplyByScalar(Matrix _MatrixA, float _Scalar)
{
	Matrix ReturnedMatrix;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ReturnedMatrix.ReplaceMatrixVal(i, j,  _MatrixA.m_MatrixArray[i][j] * _Scalar);
		}
	}
	return ReturnedMatrix;
}

Matrix Calculator::MatrixAdd(Matrix _MatrixA, Matrix _MatrixB)
{
	Matrix ReturnedMatrix;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ReturnedMatrix.ReplaceMatrixVal(i, j, _MatrixA.m_MatrixArray[i][j] + _MatrixB.m_MatrixArray[i][j]);
		}
	}
	return ReturnedMatrix;
}

Matrix Calculator::MatrixSubtract(Matrix _MatrixA, Matrix _MatrixB)
{
	Matrix ReturnedMatrix;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ReturnedMatrix.ReplaceMatrixVal(i, j, _MatrixA.m_MatrixArray[i][j] - _MatrixB.m_MatrixArray[i][j]);
		}
	}
	return ReturnedMatrix;
}

Matrix Calculator::MatrixMultiply(Matrix _MatrixA, Matrix _MatrixB)
{
	Matrix ReturnedMatrix;
	int rowB = sizeof(_MatrixB.m_MatrixArray) / sizeof(_MatrixB.m_MatrixArray[0]);
	int columnA = sizeof(_MatrixA.m_MatrixArray[0])/sizeof(float);
	//checks if youre allowed to multiply them
	if(rowB==columnA){
		
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					ReturnedMatrix.m_MatrixArray[i][j] += _MatrixA.m_MatrixArray[i][k] * _MatrixB.m_MatrixArray[k][j];
				}
			}
		}
		return ReturnedMatrix;
	}
	else {
		return Matrix();
	}
	
}

Matrix Calculator::MatrixMultiplyReverse(Matrix _MatrixA, Matrix _MatrixB)
{
	Matrix ReturnedMatrix;
	int rowB = sizeof(_MatrixA.m_MatrixArray) / sizeof(_MatrixB.m_MatrixArray[0]);
	int columnA = sizeof(_MatrixA.m_MatrixArray[0]) / sizeof(float);
	//checks if youre allowed to multiply them
	if (rowB == columnA) {

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					ReturnedMatrix.m_MatrixArray[i][j] += _MatrixB.m_MatrixArray[i][k] * _MatrixA.m_MatrixArray[k][j];
				}
			}
		}
		return ReturnedMatrix;
	}
	else {
		return Matrix();
	}

}

Matrix Calculator::GenerateIdentity(int _length)
{
	Matrix ReturnedMatrix;

	for (int i = 0; i < _length; i++) {
		for (int j = 0; j < _length; j++) {
			ReturnedMatrix.m_MatrixArray[i][j] = (j == i) ? 1 : 0;
		}
	
	}
	return ReturnedMatrix;
}
