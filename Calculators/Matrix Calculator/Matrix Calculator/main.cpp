#include <iostream>
#include "Calculator.h"

int main() {
    Matrix MatA;
    Matrix MatB;
    Calculator MainCalculator;

    MatB.LoadFromFile("Matrix.txt", MatrixB);
    MatA.LoadFromFile("Matrix.txt", MatrixA);
   
    //int a = MainCalculator.GetDeterminant4x4(MatA);
    //std::cout << a;
    //MainCalculator.GetCofactor4x4(MatA).PrintMatrix();
    //MainCalculator.MultiplyByScalar(MatA, 0.2).PrintMatrix();
    //MainCalculator.GetInverse(MatA).PrintMatrix();
    //MainCalculator.MatrixAdd(MatA, MatB).PrintMatrix();
    //MainCalculator.MatrixSubtract(MatA, MatB).PrintMatrix();
    return 0;
}