#pragma once
#include <iostream>
#include <fstream>



enum LoadedValues {
	MatrixA,
	MatrixB
};

class Matrix
{
public:
	float m_MatrixArray[4][4];

	Matrix();
	~Matrix();

	// Matrix Functions
	void PrintMatrix();
	void ReplaceMatrixVal(int _RowNum, int _ColNum, float _Replacement);
	void LoadFromFile(const char* _Filename, LoadedValues _ValueType);

	// Matrix Calculations

};

