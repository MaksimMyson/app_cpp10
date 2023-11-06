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
T** shiftMatrix(T** arr, size_t rows, size_t cols, int shiftCount, bool horizontal) {
    if (horizontal) {
        // Циклічний зсув горизонтально
        shiftCount %= cols;
        if (shiftCount < 0) {
            shiftCount += cols;
        }

        T** newArr = new T * [rows];
        for (size_t i = 0; i < rows; i++) {
            newArr[i] = new T[cols];
            for (size_t j = 0; j < cols; j++) {
                newArr[i][j] = arr[i][(j + shiftCount) % cols];
            }
        }

        return newArr;
    }
    else {
        // Циклічний зсув вертикально
        shiftCount %= rows;
        if (shiftCount < 0) {
            shiftCount += rows;
        }

        T** newArr = new T * [rows];
        for (size_t i = 0; i < rows; i++) {
            newArr[i] = new T[cols];
            for (size_t j = 0; j < cols; j++) {
                newArr[i][j] = arr[(i + shiftCount) % rows][j];
            }
        }

        return newArr;
    }
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

    int shiftCount;
    bool horizontal;
    cout << "Enter the number of shifts: ";
    cin >> shiftCount;
    cout << "Enter the direction (0 for vertical, 1 for horizontal): ";
    cin >> horizontal;

    arr = shiftMatrix(arr, rows, cols, shiftCount, horizontal);

    cout << "Array after cyclic shift:" << endl;
    showArray(arr, rows, cols);

    
    for (size_t i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}