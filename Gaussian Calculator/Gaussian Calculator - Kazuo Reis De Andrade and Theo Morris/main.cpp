#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <vector>



int main() {
    Matrix matrixA;
    matrixA.loadFromFile("Gaussian.txt");

    std::cout << "Original Matrix:" << std::endl;
    matrixA.PrintMatrix();

    // Perform Gaussian Elimination
    matrixA.gaussianEliminationReducedEchelon();
  //  matrixA.toRowEchelonForm();

    // Display the matrix after Gaussian Elimination
    std::cout << "Matrix after Gaussian Elimination:" << std::endl;
    matrixA.PrintMatrix();

    // Check and display Row Echelon form
    if (matrixA.isRowEchelonForm()) {
        std::cout << "Matrix is in Row Echelon form." << std::endl;
    }
    else {
        std::cout << "Matrix is NOT in Row Echelon form." << std::endl;
    }

    // Check and display Reduced Row Echelon form
    if (matrixA.isReducedRowEchelonForm()) {
        std::cout << "Matrix is in Reduced Row Echelon form." << std::endl;
    }
    else {
        std::cout << "Matrix is NOT in Reduced Row Echelon form." << std::endl;
    }

    return 0;
}
