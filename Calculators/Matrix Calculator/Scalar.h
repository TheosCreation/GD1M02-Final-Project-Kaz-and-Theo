
#pragma once
#include <iostream>
#include <fstream>

class Scalar
{
public: 
	float m_Scalar = 0;

	Scalar(const char* _Filename);
	~Scalar();
};

