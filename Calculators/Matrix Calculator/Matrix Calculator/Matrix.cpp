#include "Matrix.h"

Matrix::Matrix()
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			m_MatrixArray[i][j] = 0;
		}
	}
}

Matrix::~Matrix()
{
}

void Matrix::PrintMatrix()
{
	std::cout << "[";
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			std::cout << m_MatrixArray[i][j];
			std::cout << " ";
		}
		std::cout<<"]\n[";
	}
}

void Matrix::ReplaceMatrixPos(int _RowNum, int _ColNum, int _Replacement)
{

}
