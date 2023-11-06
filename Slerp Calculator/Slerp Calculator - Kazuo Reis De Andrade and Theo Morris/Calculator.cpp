#include "Calculator.h"
Quaternion Calculator::Inverse(Quaternion _Quaternion)
{
	Quaternion ReturnQuaternion(0, 0, 0, 0);
	float MagnitudeSquared = _Quaternion.m_QuaternionArray[0] * _Quaternion.m_QuaternionArray[0] +
		_Quaternion.m_QuaternionArray[1] * _Quaternion.m_QuaternionArray[1] +
		_Quaternion.m_QuaternionArray[2] * _Quaternion.m_QuaternionArray[2] +
		_Quaternion.m_QuaternionArray[3] * _Quaternion.m_QuaternionArray[3];
	if (MagnitudeSquared == 0) {
		return ReturnQuaternion;
	}
	else {
		float ReciprocalMagnitudeSquared = 1.0 / MagnitudeSquared;
		ReturnQuaternion.m_QuaternionArray[0] = _Quaternion.m_QuaternionArray[0] * ReciprocalMagnitudeSquared;
		ReturnQuaternion.m_QuaternionArray[1] = -_Quaternion.m_QuaternionArray[1] * ReciprocalMagnitudeSquared;
		ReturnQuaternion.m_QuaternionArray[2] = -_Quaternion.m_QuaternionArray[2] * ReciprocalMagnitudeSquared;
		ReturnQuaternion.m_QuaternionArray[3] = -_Quaternion.m_QuaternionArray[3] * ReciprocalMagnitudeSquared;
		return ReturnQuaternion;
	}
}
Quaternion Calculator::Multiplication(Quaternion _QuaternionA, Quaternion _QuaternionB)
{
	Quaternion ReturnQuaternion(0, 0, 0, 0);
	// a = a*a-b*b-c*c-d*d
	ReturnQuaternion.m_QuaternionArray[0] = _QuaternionB.m_QuaternionArray[0] * _QuaternionA.m_QuaternionArray[0] -
		_QuaternionB.m_QuaternionArray[1] * _QuaternionA.m_QuaternionArray[1] -
		_QuaternionB.m_QuaternionArray[2] * _QuaternionA.m_QuaternionArray[2] -
		_QuaternionB.m_QuaternionArray[3] * _QuaternionA.m_QuaternionArray[3];
	// b = a*b+b*a+c*d-d*c
	ReturnQuaternion.m_QuaternionArray[0] = _QuaternionB.m_QuaternionArray[0] * _QuaternionA.m_QuaternionArray[1] +
		_QuaternionB.m_QuaternionArray[1] * _QuaternionA.m_QuaternionArray[0] +
		_QuaternionB.m_QuaternionArray[2] * _QuaternionA.m_QuaternionArray[3] -
		_QuaternionB.m_QuaternionArray[3] * _QuaternionA.m_QuaternionArray[2];
	// c = a*c-b*d+c*a+d*b
	ReturnQuaternion.m_QuaternionArray[0] = _QuaternionB.m_QuaternionArray[0] * _QuaternionA.m_QuaternionArray[2] -
		_QuaternionB.m_QuaternionArray[1] * _QuaternionA.m_QuaternionArray[3] +
		_QuaternionB.m_QuaternionArray[2] * _QuaternionA.m_QuaternionArray[0] +
		_QuaternionB.m_QuaternionArray[3] * _QuaternionA.m_QuaternionArray[1];
	// d = a*d+b*c-c*b+d*a
	ReturnQuaternion.m_QuaternionArray[0] = _QuaternionB.m_QuaternionArray[0] * _QuaternionA.m_QuaternionArray[3] +
		_QuaternionB.m_QuaternionArray[1] * _QuaternionA.m_QuaternionArray[2] -
		_QuaternionB.m_QuaternionArray[2] * _QuaternionA.m_QuaternionArray[1] +
		_QuaternionB.m_QuaternionArray[3] * _QuaternionA.m_QuaternionArray[0];
	return ReturnQuaternion;
}

