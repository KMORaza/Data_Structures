#include <iostream>
#include <vector>
int getMax(const std::vector<int>& arr) {
    int max = arr[0];
    for (int i : arr) {
        if (i > max) {
            max = i;
        }
    }
    return max;
}
void countingSort(std::vector<int>& arr, int exp) {
    const int n = arr.size();
    std::vector<int> output(n);
    const int radix = 10;
    std::vector<int> count(radix, 0);
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % radix]++;
    }
    for (int i = 1; i < radix; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % radix] - 1] = arr[i];
        count[(arr[i] / exp) % radix]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void radixSort(std::vector<int>& arr) {
    int max = getMax(arr);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}
void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    std::cout << "Original Array: ";
    printArray(arr);
    radixSort(arr);
    std::cout << "Sorted Array: ";
    printArray(arr);
    return 0;
}
