#include <iostream>
#include "Matrix.h"


int main() {
    Matrix TestMatrix;

    TestMatrix = TestMatrix.LoadFromFile("Matrix.txt");

    TestMatrix.PrintMatrix();

    return 0;
}