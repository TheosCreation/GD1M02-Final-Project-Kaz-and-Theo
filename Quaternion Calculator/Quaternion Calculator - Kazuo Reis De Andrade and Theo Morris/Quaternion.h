#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>

enum LoadedValues {
	QuaternionA,
	QuaternionB
};

class Quaternion
{
public:
	Quaternion(double a, double b, double c, double d){};
	~Quaternion();

    
	int m_QuaternionArray[4];

	void PrintQuaternion();
	void LoadFromFile(const char* _Filename, LoadedValues _ValueType);
};

