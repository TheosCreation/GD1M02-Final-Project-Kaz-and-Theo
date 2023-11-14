#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

const std::vector<std::vector<double>>& Matrix::getMatrix() const
{
    return m_MatrixArray;
}

void Matrix::PrintMatrix() const {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << m_MatrixArray[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::loadFromFile(const char* _Filename) {
    std::ifstream file(_Filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return;
    }

    // Clear existing data and resize the matrix
    m_MatrixArray.clear();
    m_MatrixArray.resize(numRows, std::vector<double>(numCols, 0.0));

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
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
void Matrix::multiplyRow(int row, double scalar) {
    for (int i = 0; i < m_MatrixArray[row].size(); i++) {
        m_MatrixArray[row][i] *= scalar;
    }
}

// Function to perform elementary row operation: Add a multiple of one row to another row
void Matrix::addMultipleOfRow(int targetRow, int sourceRow, double multiple) {
    for (int i = 0; i < m_MatrixArray[targetRow].size(); ++i) {
        m_MatrixArray[targetRow][i] += multiple * m_MatrixArray[sourceRow][i];
    }
}

// Function to perform Gaussian Elimination
void Matrix::gaussianEliminationReducedEchelon() {
    int numRows = m_MatrixArray.size();
    int numCols = m_MatrixArray[0].size();

    for (int pivotRow = 0; pivotRow < numRows; ++pivotRow) {
        // Find the pivot column (the leftmost non-zero column in the current row)
        int pivotCol = 0;
        while (pivotCol < numCols && m_MatrixArray[pivotRow][pivotCol] == 0) {
            ++pivotCol;
        }

        if (pivotCol == numCols) {
            // All elements in this row are zero, move to the next row
            continue;
        }

        // Make the pivot element 1 by multiplying the row by 1/pivotElement
        double pivotElement = m_MatrixArray[pivotRow][pivotCol];
        multiplyRow(pivotRow, 1.0 / pivotElement);

        // Eliminate non-zero entries above and below the pivot
        for (int i = 0; i < numRows; ++i) {
            if (i != pivotRow && m_MatrixArray[i][pivotCol] != 0) {
                double multiple = -m_MatrixArray[i][pivotCol];
                addMultipleOfRow(i, pivotRow, multiple);
            }
        }
    }
}

// Function to perform Gaussian Elimination
void Matrix::gaussianEliminationEchelon() {
    int numRows = m_MatrixArray.size();
    int numCols = m_MatrixArray[0].size();
    for (int pivotRow = 0; pivotRow < numRows; ++pivotRow) {
        // Find the pivot column (the leftmost non-zero column in the current row)
        int pivotCol = 0;
        while (pivotCol < numCols && m_MatrixArray[pivotRow][pivotCol] == 0) {
            ++pivotCol;
        }

        if (pivotCol == numCols) {
            // All elements in this row are zero, move to the next row
            continue;
        }

        // Make the pivot element 1 by multiplying the row by 1/pivotElement
        double pivotElement = m_MatrixArray[pivotRow][pivotCol];
        multiplyRow(pivotRow, (1.0f / pivotElement));

        //// Eliminate non-zero entries above and below the pivot
        //for (int i = 0; i < numRows; ++i) {
        //    if (i != pivotRow && m_MatrixArray[i][pivotCol] != 0) {
        //        double multiple = -m_MatrixArray[i][pivotCol];
        //        addMultipleOfRow(i, pivotRow, multiple);
        //    }
        //}
    }
}

// Function to check if the matrix is in Row Echelon form
bool Matrix::isRowEchelonForm() const {
    int numRows = m_MatrixArray.size();
    int numCols = m_MatrixArray[0].size();

    int leadingZeroCol = -1;
    for (int i = 0; i < numRows; ++i) {
        bool foundNonZero = false;
        for (int j = 0; j < numCols; ++j) {
            if (m_MatrixArray[i][j] != 0) {
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
bool Matrix::isReducedRowEchelonForm() const {
    if (!isRowEchelonForm()) {
        return false;
    }

    int numRows = m_MatrixArray.size();
    int numCols = m_MatrixArray[0].size();

    for (int i = 0; i < numRows; ++i) {
        // Find the leading 1 in each row
        bool foundLeadingOne = false;
        int leadingOneCol = 0;
        for (int j = 0; j < numCols; ++j) {
            if (m_MatrixArray[i][j] == 1) {
                foundLeadingOne = true;
                leadingOneCol = j;
                break;
            }
        }

        // Check that the leading 1 is the only non-zero entry in its column
        for (int k = 0; k < numRows; ++k) {
            if (k != i && m_MatrixArray[k][leadingOneCol] != 0) {
                return false;
            }
        }

        if (!foundLeadingOne) {
            return false; // No leading 1 found in this row
        }
    }

    return true;
}
