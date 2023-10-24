#pragma once
#include <iostream>
#include <fstream>



enum LoadedValues {
	MatrixA,
	MatrixB,
};

class Matrix
{
public:
	int m_MatrixArray[4][4];
	
	Matrix();
	~Matrix();

	// Matrix Functions
	void PrintMatrix();
	void ReplaceMatrixVal(int _RowNum, int _ColNum, int _Replacement);
	void LoadFromFile(const char* _Filename, LoadedValues _ValueType);

	// Matrix Calculations
	
};

