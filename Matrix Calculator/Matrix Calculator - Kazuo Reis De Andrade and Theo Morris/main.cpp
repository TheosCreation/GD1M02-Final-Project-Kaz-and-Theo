#include <iostream>
#include "Calculator.h"


int main() {
    Calculator MainCalculator;
    Matrix MatA;
    Matrix MatB;
    // creates a scalar with a value loaded from Matrix.txt
    Scalar Scl("Matrix.txt");

    //loads two matrixies from the file Matrix.txt
    MatB.LoadFromFile("Matrix.txt", MatrixB);
    MatA.LoadFromFile("Matrix.txt", MatrixA);

    std::cout << "Determinant Matrix A" << "\n";
    std::cout << MainCalculator.GetDeterminant4x4(MatA) << "\n\n";
    std::cout << "Determinant Matrix B" << "\n";
    std::cout << MainCalculator.GetDeterminant4x4(MatB) << "\n\n";

    std::cout << "Transposed Matrix A" << "\n";
    MainCalculator.GetTranspose(MatA).PrintMatrix();
    std::cout << "\n" << "Transposed Matrix B" << "\n";
    MainCalculator.GetTranspose(MatB).PrintMatrix();

    std::cout << "\n" << "Inversed Matrix A" << "\n";
    MainCalculator.GetInverse(MatA).PrintMatrix();
    std::cout << "\n" << "Inversed Matrix B" << "\n";
    MainCalculator.GetInverse(MatB).PrintMatrix();

    std::cout << "\n" << "Matrix A Multiplied by Scalar value" << "\n";
    MainCalculator.MultiplyByScalar(MatA, Scl.m_Scalar).PrintMatrix();
    std::cout << "\n" << "Matrix B Multiplied by Scalar value" << "\n";
    MainCalculator.MultiplyByScalar(MatB, Scl.m_Scalar).PrintMatrix();

    std::cout << "\n" << "Matrix A + Matrix B" << "\n";
    MainCalculator.MatrixAdd(MatA, MatB).PrintMatrix();

    std::cout << "\n" << "Matrix A - Matrix B" << "\n";
    MainCalculator.MatrixSubtract(MatA, MatB).PrintMatrix();

    std::cout << "\n" << "Matrix A * Matrix B" << "\n";
    MainCalculator.MatrixMultiply(MatA, MatB).PrintMatrix();

    std::cout << "\n" << "Matrix B * Matrix A" << "\n";
    MainCalculator.MatrixMultiplyReverse(MatA, MatB).PrintMatrix();

    std::cout << "\n" << "Generated Identity Matrix" << "\n";
    MainCalculator.GenerateIdentity(4).PrintMatrix();
    int a;
    std::cin >> a;

    return 0;
}