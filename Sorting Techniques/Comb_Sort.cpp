#include <iostream>
#include <vector>
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void combSort(std::vector<int>& arr) {
    int n = arr.size();
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;
        swapped = false;
        for (int i = 0; i < n - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}
int main() {
    std::vector<int> arr = {5, 2, 1, 4, 3};
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    combSort(arr);
    std::cout << "\nSorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
