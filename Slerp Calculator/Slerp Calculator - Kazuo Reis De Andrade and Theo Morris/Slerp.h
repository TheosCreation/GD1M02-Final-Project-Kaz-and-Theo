#pragma once
#include "Calculator.h"
class Slerp
{
public:
	Quaternion d;
	Quaternion a;
	Quaternion b;
	float t;
	Slerp(Quaternion _a, Quaternion _b, float _t);
	~Slerp();
};

