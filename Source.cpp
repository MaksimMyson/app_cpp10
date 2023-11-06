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
T** addColumnAtIndex(T** arr, size_t rows, size_t& cols, size_t columnIndex) {
    if (columnIndex < 1 || columnIndex > cols + 1) {
        cout << "Invalid column index." << endl;
        return arr;
    }

    for (size_t i = 0; i < rows; i++) {
        T* newColumn = new T[cols + 1];
        for (size_t j = 0; j < columnIndex - 1; j++) {
            newColumn[j] = arr[i][j];
        }
        newColumn[columnIndex - 1] = rand() % 10; 
        for (size_t j = columnIndex - 1; j < cols; j++) {
            newColumn[j + 1] = arr[i][j];
        }
        delete[] arr[i];
        arr[i] = newColumn;
    }

    cols++;
    return arr;
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

    size_t columnIndex;
    cout << "Enter the index of the column to add: ";
    cin >> columnIndex;

    arr = addColumnAtIndex(arr, rows, cols, columnIndex);

    cout << "Array after adding the column:" << endl;
    showArray(arr, rows, cols);

   
    for (size_t i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}