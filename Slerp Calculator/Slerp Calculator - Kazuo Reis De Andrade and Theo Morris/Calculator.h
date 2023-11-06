#pragma once
#include "Quaternion.h"
#include <cmath>
class Calculator
{
public:
	// Adds like terms of the quaternions
	Quaternion Inverse(Quaternion _Quaternion);
	Quaternion Normalised(Quaternion _Quaternion);
	Quaternion ScalarMultiplication(Quaternion _Quaternion, int _Scalar);
	float ToAxisAngle(Quaternion _Quaternion);
	Quaternion Slerp(Quaternion _a, Quaternion _b, float _t);
};

