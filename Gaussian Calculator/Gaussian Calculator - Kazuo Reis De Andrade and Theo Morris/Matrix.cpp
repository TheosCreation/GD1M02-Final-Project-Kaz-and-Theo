#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

void Matrix::PrintMatrix()
{
    std::cout << "[";
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << m_MatrixArray[i][j];
            std::cout << " ";
        }
        if (i == 2) {
            std::cout << "]\n";
        }
        else {
            std::cout << "]\n[";
        }

    }
}

void Matrix::LoadFromFile(const char* _Filename) {
    std::ifstream file(_Filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (file >> m_MatrixArray[i][j]) {
                // loaded a number into the array
            }
            else {
                std::cerr << "Error: Could not read data from the file." << std::endl;
                file.close();
                return;
            }
        }
    }

    file.close();
}

// Function to perform elementary row operation: Multiply a row by a scalar
void Matrix::multiplyRow(std::vector<std::vector<double>>& matrix, int row, double scalar){
    for (double& element : matrix[row]) {
        element *= scalar;
    }
}

// Function to perform elementary row operation: Add a multiple of one row to another row
void Matrix::addMultipleOfRow(std::vector<std::vector<double>>& matrix, int targetRow, int sourceRow, double multiple) {
    for (size_t i = 0; i < matrix[targetRow].size(); ++i) {
        matrix[targetRow][i] += multiple * matrix[sourceRow][i];
    }
}

// Function to perform Gaussian Elimination
void Matrix::gaussianElimination(std::vector<std::vector<double>>& matrix) {
    size_t numRows = matrix.size();
    size_t numCols = matrix[0].size();

    for (size_t pivotRow = 0; pivotRow < numRows; ++pivotRow) {
        // Find the pivot column (the leftmost non-zero column in the current row)
        size_t pivotCol = 0;
        while (pivotCol < numCols && matrix[pivotRow][pivotCol] == 0) {
            ++pivotCol;
        }

        if (pivotCol == numCols) {
            // All elements in this row are zero, move to the next row
            continue;
        }

        // Make the pivot element 1 by multiplying the row by 1/pivotElement
        double pivotElement = matrix[pivotRow][pivotCol];
        multiplyRow(matrix, pivotRow, 1.0 / pivotElement);

        // Eliminate non-zero entries above and below the pivot
        for (size_t i = 0; i < numRows; ++i) {
            if (i != pivotRow && matrix[i][pivotCol] != 0) {
                double multiple = -matrix[i][pivotCol];
                addMultipleOfRow(matrix, i, pivotRow, multiple);
            }
        }
    }
}

// Function to check if the matrix is in Row Echelon form
bool Matrix::isRowEchelonForm(const std::vector<std::vector<double>>& matrix) {
    size_t numRows = matrix.size();
    size_t numCols = matrix[0].size();

    int leadingZeroCol = -1;
    for (size_t i = 0; i < numRows; ++i) {
        bool foundNonZero = false;
        for (size_t j = 0; j < numCols; ++j) {
            if (matrix[i][j] != 0) {
                foundNonZero = true;
                if (static_cast<int>(j) > leadingZeroCol) {
                    leadingZeroCol = j;
                }
                break;
            }
        }
        if (!foundNonZero) {
            continue; // Skip rows with all zeros
        }
        if (leadingZeroCol == -1 || static_cast<int>(i) < leadingZeroCol) {
            return false; // Not in Row Echelon form
        }
    }
    return true;
}

// Function to check if the matrix is in Reduced Row Echelon form
bool Matrix::isReducedRowEchelonForm(const std::vector<std::vector<double>>& matrix) {
    if (!isRowEchelonForm(matrix)) {
        return false;
    }

    size_t numRows = matrix.size();
    size_t numCols = matrix[0].size();

    for (size_t i = 0; i < numRows; ++i) {
        // Find the leading 1 in each row
        bool foundLeadingOne = false;
        size_t leadingOneCol = 0;
        for (size_t j = 0; j < numCols; ++j) {
            if (matrix[i][j] == 1) {
                foundLeadingOne = true;
                leadingOneCol = j;
                break;
            }
        }

        // Check that the leading 1 is the only non-zero entry in its column
        for (size_t k = 0; k < numRows; ++k) {
            if (k != i && matrix[k][leadingOneCol] != 0) {
                return false;
            }
        }

        if (!foundLeadingOne) {
            return false; // No leading 1 found in this row
        }
    }

    return true;
}
