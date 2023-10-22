#pragma once

class Matrix
{
public:
	int m_MatrixArray[4][4];
	
	Matrix();
	~Matrix();

	void PrintMatrix();
	void ReplaceMatrixPos(int _RowNum, int _ColNum, int _Replacement);
};

