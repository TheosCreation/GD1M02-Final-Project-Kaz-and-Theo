#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

enum LoadedValues {
	QuaternionA,
	QuaternionB
};

class Quaternion
{
public:
	Quaternion(float a = 0, float b = 0, float c = 0, float d = 0);
	~Quaternion();


	float m_QuaternionArray[4];

	void PrintQuaternion();
	void LoadFromFile(const char* _Filename, LoadedValues _ValueType);
};

