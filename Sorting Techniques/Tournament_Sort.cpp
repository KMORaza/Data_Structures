#include <iostream>
#include <vector>
int tournamentMin(std::vector<int>& arr, int i, int j) {
    int winner = i;
    while (++i <= j) {
        if (arr[i] < arr[winner]) {
            winner = i;
        }
    }
    return winner;
}
void tournamentSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int winner = tournamentMin(arr, low, high);
        std::swap(arr[low], arr[winner]);
        tournamentSort(arr, low + 1, high);
    }
}
int main() {
    std::vector<int> arr = {3, 7, 4, 8, 6, 2, 1, 5};
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    tournamentSort(arr, 0, arr.size() - 1);
    std::cout << "\nSorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
