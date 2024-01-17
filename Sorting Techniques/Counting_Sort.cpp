#include <iostream>
#include <vector>
void countingSort(std::vector<int>& arr) {
    int max = *std::max_element(arr.begin(), arr.end());
    std::vector<int> count(max + 1, 0);
    for (int num : arr) {
        count[num]++;
    }
    int index = 0;
    for (int i = 0; i <= max; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}
int main() {
    std::vector<int> arr = {4, 2, 7, 1, 9, 3, 5, 8, 6};
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    countingSort(arr);
    std::cout << "\nSorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
