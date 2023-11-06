#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
void showArray(T** arr, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
T** deleteRow(T** arr, size_t& rows, size_t cols, size_t rowIndex) {
    if (rowIndex < 0 || rowIndex >= rows) {
        cout << "Invalid row index." << endl;
        return arr;
    }

    T** newArr = new T * [rows - 1];
    for (size_t i = 0, newRow = 0; i < rows; i++) {
        if (i == rowIndex) {
            delete[] arr[i];
        }
        else {
            newArr[newRow] = new T[cols];
            for (size_t j = 0; j < cols; j++) {
                newArr[newRow][j] = arr[i][j];
            }
            newRow++;
        }
    }

    delete[] arr;
    rows--;
    return newArr;
}

int main() {
    srand(time(0));

    size_t rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** arr = new int* [rows];
    for (size_t i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (size_t j = 0; j < cols; j++) {
            arr[i][j] = rand() % 10;
        }
    }

    cout << "Original Array:" << endl;
    showArray(arr, rows, cols);

    size_t rowIndex;
    cout << "Enter the index of the row to delete: ";
    cin >> rowIndex;

    arr = deleteRow(arr, rows, cols, rowIndex);

    cout << "Array after deleting the row:" << endl;
    showArray(arr, rows, cols);

    
    for (size_t i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}