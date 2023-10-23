#include <iostream>
#include "Matrix.h"


int main() {
    Matrix TestMatrix;
 

    TestMatrix.LoadFromFile("Matrix.txt", MatrixB);

   
    int a = TestMatrix.GetDeterminant();
    TestMatrix.PrintMatrix();

    return 0;
}