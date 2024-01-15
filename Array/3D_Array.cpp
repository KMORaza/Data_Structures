// Implementing 3D array with all operations
#include <iostream>
const int MAX_DIM1 = 10;
const int MAX_DIM2 = 10;
const int MAX_DIM3 = 10;
void displayArray(int arr[MAX_DIM1][MAX_DIM2][MAX_DIM3], int dim1, int dim2, int dim3) {
    std::cout << "Array elements:\n";
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                std::cout << arr[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}
void addArrays(int arr1[MAX_DIM1][MAX_DIM2][MAX_DIM3], int arr2[MAX_DIM1][MAX_DIM2][MAX_DIM3], int result[MAX_DIM1][MAX_DIM2][MAX_DIM3], int dim1, int dim2, int dim3) {
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                result[i][j][k] = arr1[i][j][k] + arr2[i][j][k];
            }
        }
    }
}
void multiplyArrays(int arr1[MAX_DIM1][MAX_DIM2][MAX_DIM3], int arr2[MAX_DIM1][MAX_DIM2][MAX_DIM3], int result[MAX_DIM1][MAX_DIM2][MAX_DIM3], int dim1, int dim2, int dim3) {
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                result[i][j][k] = 0;
                for (int l = 0; l < dim3; ++l) {
                    result[i][j][k] += arr1[i][j][l] * arr2[l][j][k];
                }
            }
        }
    }
}
void updateElement(int arr[MAX_DIM1][MAX_DIM2][MAX_DIM3], int dim1, int dim2, int dim3) {
    int x, y, z, newValue;
    std::cout << "Enter the dimensions (x, y, z) of the element to update: ";
    std::cin >> x >> y >> z;
    if (x >= 0 && x < dim1 && y >= 0 && y < dim2 && z >= 0 && z < dim3) {
        std::cout << "Enter the new value: ";
        std::cin >> newValue;

        arr[x][y][z] = newValue;
        std::cout << "Element updated successfully.\n";
    } else {
        std::cout << "Invalid dimensions. Please enter valid indices.\n";
    }
}
bool linearSearch(int arr[MAX_DIM1][MAX_DIM2][MAX_DIM3], int dim1, int dim2, int dim3, int target, int& foundX, int& foundY, int& foundZ) {
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                if (arr[i][j][k] == target) {
                    foundX = i;
                    foundY = j;
                    foundZ = k;
                    return true;
                }
            }
        }
    }
    return false;
}
int main() {
    int array[MAX_DIM1][MAX_DIM2][MAX_DIM3];
    int dim1, dim2, dim3;
    std::cout << "Enter the dimensions for the 3D array: ";
    std::cin >> dim1 >> dim2 >> dim3;
    std::cout << "Enter the elements for the 3D array:\n";
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                std::cout << "Element [" << i << "][" << j << "][" << k << "]: ";
                std::cin >> array[i][j][k];
            }
        }
    }

    int choice;
    do {
        std::cout << "\n3D Array Operations Menu:\n";
        std::cout << "1. Display 3D Array\n";
        std::cout << "2. Add 3D Arrays\n";
        std::cout << "3. Multiply 3D Arrays\n";
        std::cout << "4. Update Element\n";
        std::cout << "5. Linear Search\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayArray(array, dim1, dim2, dim3);
                break;
            case 2: {
                int array2[MAX_DIM1][MAX_DIM2][MAX_DIM3];
                int result[MAX_DIM1][MAX_DIM2][MAX_DIM3];
                std::cout << "Enter the second 3D array:\n";
                for (int i = 0; i < dim1; ++i) {
                    for (int j = 0; j < dim2; ++j) {
                        for (int k = 0; k < dim3; ++k) {
                            std::cout << "Element [" << i << "][" << j << "][" << k << "]: ";
                            std::cin >> array2[i][j][k];
                        }
                    }
                }
                addArrays(array, array2, result, dim1, dim2, dim3);
                std::cout << "Resultant 3D Array after Addition:\n";
                displayArray(result, dim1, dim2, dim3);
                break;
            }
            case 3: {
                int array2[MAX_DIM1][MAX_DIM2][MAX_DIM3];
                int result[MAX_DIM1][MAX_DIM2][MAX_DIM3];
                std::cout << "Enter the second 3D array:\n";
                for (int i = 0; i < dim1; ++i) {
                    for (int j = 0; j < dim2; ++j) {
                        for (int k = 0; k < dim3; ++k) {
                            std::cout << "Element [" << i << "][" << j << "][" << k << "]: ";
                            std::cin >> array2[i][j][k];
                        }
                    }
                }
                multiplyArrays(array, array2, result, dim1, dim2, dim3);
                std::cout << "Resultant 3D Array after Multiplication:\n";
                displayArray(result, dim1, dim2, dim3);
                break;
            }
            case 4:
                updateElement(array, dim1, dim2, dim3);
                break;
            case 5: {
                int target, foundX, foundY, foundZ;
                std::cout << "Enter the element to search: ";
                std::cin >> target;
                if (linearSearch(array, dim1, dim2, dim3, target, foundX, foundY, foundZ)) {
                    std::cout << "Element found at position [" << foundX << "][" << foundY << "][" << foundZ << "].\n";
                } else {
                    std::cout << "Element not found in the 3D array.\n";
                }
                break;
            }
            case 6:
                std::cout << "Exiting!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);
    return 0;
}
