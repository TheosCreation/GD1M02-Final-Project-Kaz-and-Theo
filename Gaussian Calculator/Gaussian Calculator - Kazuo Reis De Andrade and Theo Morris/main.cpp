#include "Matrix.h"
/*
int main() {
	Matrix matrixA;
	matrixA.LoadFromFile("Gaussian.txt");
	matrixA.PrintMatrix();


}*/
#include <iostream>
#include <fstream>
#include <vector>



int main() {
    Matrix matrixA;
    matrixA.LoadFromFile("Gaussian.txt");

    std::cout << "Original Matrix:" << std::endl;
    matrixA.PrintMatrix();

    // Perform Gaussian Elimination
    matrixA.gaussianElimination(matrixA.m_MatrixArray);

    // Display the matrix after Gaussian Elimination
    std::cout << "Matrix after Gaussian Elimination:" << std::endl;
    matrixA.PrintMatrix();

    // Check and display Row Echelon form
    if (matrixA.isRowEchelonForm(matrixA.m_MatrixArray)) {
        std::cout << "Matrix is in Row Echelon form." << std::endl;
    }
    else {
        std::cout << "Matrix is NOT in Row Echelon form." << std::endl;
    }

    // Check and display Reduced Row Echelon form
    if (matrixA.isReducedRowEchelonForm(matrixA.m_MatrixArray)) {
        std::cout << "Matrix is in Reduced Row Echelon form." << std::endl;
    }
    else {
        std::cout << "Matrix is NOT in Reduced Row Echelon form." << std::endl;
    }

    return 0;
}
