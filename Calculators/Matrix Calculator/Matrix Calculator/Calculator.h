#pragma once
#include "Matrix.h"
#include "Scalar.h"
class Calculator
{
public:
	Calculator();
	~Calculator();

	//gets the determinant
	float GetDeterminant4x4(Matrix _MatrixA);
	float GetDeterminant3x3(Matrix _MatrixA);
	Matrix GetTranspose(Matrix _MatrixA);
	Matrix GetInverse(Matrix _MatrixA);
	Matrix GetCofactor4x4(Matrix _MatrixA);
	Matrix MultiplyByScalar(Matrix _MatrixA, float _Scalar);
	Matrix MatrixAdd(Matrix _MatrixA, Matrix _MatrixB);
	Matrix MatrixSubtract(Matrix _MatrixA, Matrix _MatrixB);
	Matrix MatrixMultiply(Matrix _MatrixA, Matrix _MatrixB);
	Matrix MatrixMultiplyReverse(Matrix _MatrixA, Matrix _MatrixB);
	Matrix GenerateIdentity(int _length);
};

