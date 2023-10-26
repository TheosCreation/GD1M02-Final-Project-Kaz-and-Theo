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
		if (i == 3) {
			std::cout << "]\n";
		}
		else {
			std::cout << "]\n[";
		}

	}
}

void Matrix::ReplaceMatrixVal(int _ColNum, int _RowNum, float _Replacement)
{
	m_MatrixArray[_ColNum][_RowNum] = _Replacement;
}



void Matrix::LoadFromFile(const char* _Filename, LoadedValues _ValueType)
{
	Matrix NewMatrix;
	std::ifstream file(_Filename);
	if (!file.is_open()) {
		std::cerr << "Error: Unable to open the file." << std::endl;
		return;
	}

	std::string temp;
	switch (_ValueType) {
	case MatrixA:
		//do nothing :D
		break;
	case MatrixB:
		for (int i = 0; i < 16; i++)
		{
			file >> temp;
			//literally just skips lines LMAO
			// theres probably a better way to do this but we have like a week to do this so

		}
		break;
	default:
		std::cout << "Please Input their MatrixA or MatrixB";
		break;
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (!(file >> NewMatrix.m_MatrixArray[i][j])) {
				std::cerr << "Error: Invalid data in the file." << std::endl;
				return;
			}
		}
	}
	*this = NewMatrix;
	file.close();
}


