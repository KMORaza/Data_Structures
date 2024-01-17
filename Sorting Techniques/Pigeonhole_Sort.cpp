#include <iostream>
#include <vector>
#include <algorithm>
void pigeonholeSort(std::vector<int>& arr) {
    int minVal = *std::min_element(arr.begin(), arr.end());
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;
    std::vector<int> pigeonholes(range, 0);
    for (int num : arr) {
        pigeonholes[num - minVal]++;
    }
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (pigeonholes[i] > 0) {
            arr[index++] = i + minVal;
            pigeonholes[i]--;
        }
    }
}
int main() {
    std::vector<int> arr = {8, 3, 2, 7, 4, 6, 8};   
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    pigeonholeSort(arr);
    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
