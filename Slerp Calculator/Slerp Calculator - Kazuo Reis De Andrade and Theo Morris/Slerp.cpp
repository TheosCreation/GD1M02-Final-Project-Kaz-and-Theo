#include "Slerp.h"

Slerp::Slerp(Quaternion _a, Quaternion _b, float _t)
{
	Calculator calc; 
	a = _a;
	b = _b;
	t = _t;

	d = calc.Multiplication(b, calc.Inverse(a));
	// now convert d to axis angle
	// and power by t (d^t)
	// then multiply the answer by a

	d.PrintQuaternion();
	a.PrintQuaternion();
	b.PrintQuaternion();
}

Slerp::~Slerp()
{
}
