// Implementing 2D array with all operations
#include <iostream>
const int MAX_ROWS = 100;
const int MAX_COLS = 100;
void displayArray(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    std::cout << "Array elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}
void addMatrices(int arr1[MAX_ROWS][MAX_COLS], int arr2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}
void multiplyMatrices(int arr1[MAX_ROWS][MAX_COLS], int arr2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        std::cout << "Matrix multiplication not possible. Invalid dimensions.\n";
        return;
    }
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}
void updateElement(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int row, col, newValue;
    std::cout << "Enter the row and column of the element to update: ";
    std::cin >> row >> col;
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        std::cout << "Enter the new value: ";
        std::cin >> newValue;
        arr[row][col] = newValue;
        std::cout << "Element updated successfully.\n";
    } else {
        std::cout << "Invalid row or column. Please enter valid indices.\n";
    }
}
bool linearSearch(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int target, int& foundRow, int& foundCol) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] == target) {
                foundRow = i;
                foundCol = j;
                return true;
            }
        }
    }
    return false;
}
int main() {
    int array[MAX_ROWS][MAX_COLS];
    int rows, cols;
    std::cout << "Enter the number of rows and columns for the array: ";
    std::cin >> rows >> cols;
    std::cout << "Enter the elements for the array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> array[i][j];
        }
    }
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display Array\n";
        std::cout << "2. Add Matrices\n";
        std::cout << "3. Multiply Matrices\n";
        std::cout << "4. Update Element\n";
        std::cout << "5. Linear Search\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                displayArray(array, rows, cols);
                break;
            case 2: {
                int array2[MAX_ROWS][MAX_COLS];
                int result[MAX_ROWS][MAX_COLS];
                std::cout << "Enter the second matrix:\n";
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        std::cout << "Element [" << i << "][" << j << "]: ";
                        std::cin >> array2[i][j];
                    }
                }
                addMatrices(array, array2, result, rows, cols);
                std::cout << "Resultant Matrix after Addition:\n";
                displayArray(result, rows, cols);
                break;
            }
            case 3: {
                int array2[MAX_ROWS][MAX_COLS];
                int result[MAX_ROWS][MAX_COLS];
                std::cout << "Enter the second matrix:\n";
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        std::cout << "Element [" << i << "][" << j << "]: ";
                        std::cin >> array2[i][j];
                    }
                }
                multiplyMatrices(array, array2, result, rows, cols, rows, cols);
                std::cout << "Resultant Matrix after Multiplication:\n";
                displayArray(result, rows, cols);
                break;
            }
            case 4:
                updateElement(array, rows, cols);
                break;
            case 5: {
                int target, foundRow, foundCol;
                std::cout << "Enter the element to search: ";
                std::cin >> target;
                if (linearSearch(array, rows, cols, target, foundRow, foundCol)) {
                    std::cout << "Element found at position [" << foundRow << "][" << foundCol << "].\n";
                } else {
                    std::cout << "Element not found in the array.\n";
                }
                break;
            }
            case 6:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);
    return 0;
}
