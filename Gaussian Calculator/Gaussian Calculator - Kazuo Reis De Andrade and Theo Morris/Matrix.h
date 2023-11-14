#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Matrix
{
public:
	Matrix();
	~Matrix();
	std::vector<std::vector<double>> m_MatrixArray;
	void PrintMatrix();
	void LoadFromFile(const char* _Filename);
	void multiplyRow(std::vector<std::vector<double>>&matrix, int row, double scalar);

	void addMultipleOfRow(std::vector<std::vector<double>>& matrix, int targetRow, int sourceRow, double multiple);

	void gaussianElimination(std::vector<std::vector<double>>& matrix);

	bool isRowEchelonForm(const std::vector<std::vector<double>>& matrix);

	bool isReducedRowEchelonForm(const std::vector<std::vector<double>>& matrix);

};

