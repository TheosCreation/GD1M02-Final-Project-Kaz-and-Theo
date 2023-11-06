#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

void Matrix::PrintMatrix()
{
    std::cout << "[";
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << m_MatrixArray[i][j];
            std::cout << " ";
        }
        if (i == 2) {
            std::cout << "]\n";
        }
        else {
            std::cout << "]\n[";
        }

    }
}

void Matrix::LoadFromFile(const char* _Filename) {
    std::ifstream file(_Filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (file >> m_MatrixArray[i][j]) {
                // loaded a number into the array
            }
            else {
                std::cerr << "Error: Could not read data from the file." << std::endl;
                file.close();
                return;
            }
        }
    }

    file.close();
}