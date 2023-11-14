#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    Matrix matrixA;
    matrixA.loadFromFile("Gaussian.txt");

    std::cout << "Original Matrix:" << std::endl;
    matrixA.PrintMatrix();
    bool Reduced;
    std::cout << "0 - for Row Echelon form, 1 - Reduced Row Echelon Form: ";
    std::cin >> Reduced;
    // Perform Gaussian Elimination
    if (Reduced) {
        matrixA.gaussianEliminationReducedEchelon();
    }
    else {
        matrixA.gaussianEliminationEchelon();
    }

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
