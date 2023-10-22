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

Matrix Matrix::LoadFromFile(const char* filename)
{
	Matrix NewMatrix;
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: Unable to open the file." << std::endl;
		return NewMatrix;
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (!(file >> NewMatrix.m_MatrixArray[i][j])) {
				std::cerr << "Error: Invalid data in the file." << std::endl;
				return NewMatrix;
			}
		}
	}
	
	return NewMatrix;
}