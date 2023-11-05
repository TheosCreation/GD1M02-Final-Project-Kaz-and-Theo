#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

enum LoadedValues {
	QuaternionA,
	QuaternionB
};

class Quaternion
{
public:
	Quaternion(float a, float b, float c, float d);
	~Quaternion();


	float m_QuaternionArray[4];

	void PrintQuaternion();
	void LoadFromFile(const char* _Filename, LoadedValues _ValueType);
};

