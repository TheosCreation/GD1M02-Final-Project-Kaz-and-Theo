#pragma once
#include "Quaternion.h"
#include <cmath>
class Calculator
{
public:
	Quaternion Inverse(Quaternion _Quaternion);
	Quaternion Multiplication(Quaternion _QuaternionA, Quaternion _QuaternionB);
	void ToAxisAngle(Quaternion _Quaternion, float _Angle);
};

