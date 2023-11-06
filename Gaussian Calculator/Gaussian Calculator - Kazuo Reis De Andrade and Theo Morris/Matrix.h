#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Matrix
{
public:
	Matrix();
	~Matrix();
	int m_MatrixArray[3][4];
	void PrintMatrix();
	void LoadFromFile(const char* _Filename);
};

