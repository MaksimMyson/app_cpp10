#include <iostream>

void addRow(int**& matrix, int& numRows, int numCols, int* newRow) {
    int** newMatrix = new int* [numRows + 1];

    for (int i = 0; i < numRows; i++) {
        newMatrix[i] = new int[numCols];
        for (int j = 0; j < numCols; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
        delete[] matrix[i];
    }

    newMatrix[numRows] = new int[numCols];
    for (int j = 0; j < numCols; j++) {
        newMatrix[numRows][j] = newRow[j];
    }

    delete[] matrix;
    matrix = newMatrix;
    numRows++;
}

void printMatrix(int** matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int numRows = 3;
    int numCols = 4;

    int** matrix = new int* [numRows];
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new int[numCols];
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = i * numCols + j + 1;
        }
    }

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix, numRows, numCols);

    int newRow[] = { 13, 14, 15, 16 };
    addRow(matrix, numRows, numCols, newRow);

    std::cout << "Updated Matrix:" << std::endl;
    printMatrix(matrix, numRows, numCols);

    for (int i = 0; i < numRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}