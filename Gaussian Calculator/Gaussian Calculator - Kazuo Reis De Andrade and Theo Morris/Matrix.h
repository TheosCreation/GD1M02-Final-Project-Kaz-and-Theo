#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

class Matrix {
private:
    static const int numRows = 3;
    static const int numCols = 4;

    std::vector<std::vector<double>> m_MatrixArray;

public:
    Matrix();
    ~Matrix();

    const std::vector<std::vector<double>>& getMatrix() const;
    void PrintMatrix() const;
    void loadFromFile(const char* _Filename);

    void multiplyRow(int row, double scalar);
    void addMultipleOfRow(int targetRow, int sourceRow, double multiple);
    void gaussianEliminationReducedEchelon();
    void gaussianEliminationEchelon();

    bool isRowEchelonForm() const;
    bool isReducedRowEchelonForm() const;
    void toRowEchelonForm();
};
