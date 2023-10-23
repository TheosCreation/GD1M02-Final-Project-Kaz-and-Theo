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

void Matrix::ReplaceMatrixVal( int _ColNum, int _RowNum, int _Replacement)
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

float Matrix::GetDeterminant()
{
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			for (int k = i + 1; k < 4; k++) {
				m_MatrixArray[j][k] = m_MatrixArray[j][k] * m_MatrixArray[i][i] - m_MatrixArray[j][i] * m_MatrixArray[i][k];
				if (i != 0) {
					m_MatrixArray[j][k] /= m_MatrixArray[i - 1][i - 1];
				}
			}
		}
	}
	return m_MatrixArray[3][3];
}
