#pragma once
#include "Quaternion.h"
#include <math.h>
class Calculator
{
public:
	Calculator();
	~Calculator();

	// Adds like terms of the quaternions
	Quaternion Addition(Quaternion _QuaternionA, Quaternion _QuaternionB);
	// Subtracts like terms of the quaternions
	Quaternion Subtraction(Quaternion _QuaternionA, Quaternion _QuaternionB);
	// Subtracts like terms of the quaternions in reverse order
	Quaternion SubtractionReverse(Quaternion _QuaternionA, Quaternion _QuaternionB);
	// Does somthing fancy
	Quaternion Multiplication(Quaternion _QuaternionA, Quaternion _QuaternionB);
	// Does somthing fancy but in reverse
	Quaternion MultiplicationReverse(Quaternion _QuaternionA, Quaternion _QuaternionB);
	// Multiplys like terms of the quaternions
	Quaternion DotProduct(Quaternion _QuaternionA, Quaternion _QuaternionB);
	// Multiplys the imaginary parts by -1
	Quaternion Conjugate(Quaternion _Quaternion);

	Quaternion Inverse(Quaternion _Quaternion);
	// Multiplys each part by the scalar
	Quaternion ScalarMultiplication(Quaternion _Quaternion, int _Scalar);

	Quaternion Normalised(Quaternion _Quaternion);
};