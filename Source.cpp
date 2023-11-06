#include <iostream>

using namespace std;

const int numCols = 4;

void addRowToBeginning(int**& matrix, int& numRows, int* newRow) {
    int** newMatrix = new int* [numRows + 1];

    newMatrix[0] = new int[numCols];
    for (int j = 0; j < numCols; j++) {
        newMatrix[0][j] = newRow[j];
    }

    for (int i = 1; i < numRows + 1; i++) {
        newMatrix[i] = new int[numCols];
        for (int j = 0; j < numCols; j++) {
            for (int j = 0; j < numCols; j++) {
                newMatrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    delete[] matrix;
    matrix = newMatrix;
    numRows++;
}

void printMatrix(int** matrix, int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numRows = 3;

    int** matrix = new int* [numRows];
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new int[numCols];
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = i * numCols + j + 1;
        }
    }

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, numRows);

    int newRow[numCols] = { 13, 14, 15, 16 };
    addRowToBeginning(matrix, numRows, newRow);

    cout << "Updated Matrix:" << endl;
    printMatrix(matrix, numRows);

    for (int i = 0; i < numRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}