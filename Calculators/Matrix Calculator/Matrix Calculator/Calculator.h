#pragma once
#include "Matrix.h"
class Calculator
{
public:
	Calculator();
	~Calculator();

	int GetDeterminant(Matrix _MatrixA);
	Matrix GetTranspose(Matrix _MatrixA);
	Matrix GetInverse(Matrix _MatrixA);
	Matrix MultiplyByScalar(Matrix _MatrixA, int _Scalar);
	Matrix MatrixAdd(Matrix _MatrixA, Matrix _MatrixB);
	Matrix MatrixSubtract(Matrix _MatrixA, Matrix _MatrixB);
	Matrix MatrixMultiply(Matrix _MatrixA, Matrix _MatrixB);
	Matrix MatrixMultiplyReverse(Matrix _MatrixB, Matrix _MatrixA);
	Matrix GenerateIdentity();
};

