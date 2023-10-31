#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

enum LoadedValues {
	QuaternionA,
	QuaternionB
};

class Quaternion
{
public:
	Quaternion(int a, int b, int c, int d);
	~Quaternion();

    
	int m_QuaternionArray[4];

	void PrintQuaternion();
	void LoadFromFile(const char* _Filename, LoadedValues _ValueType);
};

