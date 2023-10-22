#include <iostream>
#include "Matrix.h"


int main() {
    Matrix TestMatrix;
 

    TestMatrix.LoadFromFile("Matrix.txt", MatrixB);

   

    TestMatrix.PrintMatrix();

    return 0;
}