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

Quaternion Calculator::Normalised(Quaternion _Quaternion)
{
	Quaternion ReturnQuaternion(0, 0, 0, 0);
	float d = sqrt((_Quaternion.m_QuaternionArray[0]) * (_Quaternion.m_QuaternionArray[0]) +
		(_Quaternion.m_QuaternionArray[1]) * (_Quaternion.m_QuaternionArray[1]) +
		(_Quaternion.m_QuaternionArray[2]) * (_Quaternion.m_QuaternionArray[2]) +
		(_Quaternion.m_QuaternionArray[3]) * (_Quaternion.m_QuaternionArray[3]));
	ReturnQuaternion.m_QuaternionArray[0] = _Quaternion.m_QuaternionArray[0] / d;
	ReturnQuaternion.m_QuaternionArray[1] = _Quaternion.m_QuaternionArray[1] / d;
	ReturnQuaternion.m_QuaternionArray[2] = _Quaternion.m_QuaternionArray[2] / d;
	ReturnQuaternion.m_QuaternionArray[3] = _Quaternion.m_QuaternionArray[3] / d;
	return ReturnQuaternion;
}

Quaternion Calculator::ScalarMultiplication(Quaternion _Quaternion, int _Scalar)
{
	Quaternion ReturnQuaternion(0, 0, 0, 0);
	ReturnQuaternion.m_QuaternionArray[0] = _Quaternion.m_QuaternionArray[0] * _Scalar;
	ReturnQuaternion.m_QuaternionArray[1] = _Quaternion.m_QuaternionArray[1] * _Scalar;
	ReturnQuaternion.m_QuaternionArray[2] = _Quaternion.m_QuaternionArray[2] * _Scalar;
	ReturnQuaternion.m_QuaternionArray[3] = _Quaternion.m_QuaternionArray[3] * _Scalar;
	return ReturnQuaternion;
}

float Calculator::ToAxisAngle(Quaternion _Quaternion)
{
	return acos(_Quaternion.m_QuaternionArray[0]*2);
}

Quaternion Calculator::Slerp(Quaternion _a, Quaternion _b, float _t)
{
	//New Method
	Quaternion ReturnedQuaternion(1, 0, 0, 0);


	double cosHalfTheta = _a.m_QuaternionArray[0] * _b.m_QuaternionArray[0] +
		_a.m_QuaternionArray[1] * _b.m_QuaternionArray[1] +
		_a.m_QuaternionArray[2] * _b.m_QuaternionArray[2] +
		_a.m_QuaternionArray[3] * _b.m_QuaternionArray[3];
	
	if (abs(cosHalfTheta) >= 1.0) {
		return ReturnedQuaternion;
	}
	// Calculate temporary values.
	double halfTheta = acos(cosHalfTheta);
	double sinHalfTheta = sqrt(1.0 - cosHalfTheta * cosHalfTheta);
	// if theta = 180 degrees then result is not fully defined
	// we could rotate around any axis normal to qa or qb
	if (fabs(sinHalfTheta) < 0.001) { // fabs is floating point absolute
		ReturnedQuaternion.m_QuaternionArray[0] = (_a.m_QuaternionArray[0] * 0.5 + _b.m_QuaternionArray[0] * 0.5);
		ReturnedQuaternion.m_QuaternionArray[1] = (_a.m_QuaternionArray[1] * 0.5 + _b.m_QuaternionArray[1] * 0.5);
		ReturnedQuaternion.m_QuaternionArray[2] = (_a.m_QuaternionArray[2] * 0.5 + _b.m_QuaternionArray[2] * 0.5);
		ReturnedQuaternion.m_QuaternionArray[3] = (_a.m_QuaternionArray[3] * 0.5 + _b.m_QuaternionArray[3] * 0.5);
		return ReturnedQuaternion;
	}
	double ratioA = sin((1 - _t) * halfTheta) / sinHalfTheta;
	double ratioB = sin(_t * halfTheta) / sinHalfTheta;
	//calculate Quaternion.
	ReturnedQuaternion.m_QuaternionArray[0] = (_a.m_QuaternionArray[0] * ratioA + _b.m_QuaternionArray[0] * ratioB);
	ReturnedQuaternion.m_QuaternionArray[1] = (_a.m_QuaternionArray[1] * ratioA + _b.m_QuaternionArray[1] * ratioB);
	ReturnedQuaternion.m_QuaternionArray[2] = (_a.m_QuaternionArray[2] * ratioA + _b.m_QuaternionArray[2] * ratioB);
	ReturnedQuaternion.m_QuaternionArray[3] = (_a.m_QuaternionArray[3] * ratioA + _b.m_QuaternionArray[3] * ratioB);
	return ReturnedQuaternion;
}

