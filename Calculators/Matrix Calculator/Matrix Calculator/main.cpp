#include <iostream>
#include "Calculator.h"

int main() {
    Matrix MatA;
    Matrix MatB;
    Calculator MainCalculator;

    MatB.LoadFromFile("Matrix.txt", MatrixB);
    MatA.LoadFromFile("Matrix.txt", MatrixA);

   
    int a = MainCalculator.GetDeterminant(MatA);
    MainCalculator.GetTranspose(MatA).PrintMatrix();
    //MatA.PrintMatrix();

    return 0;
}