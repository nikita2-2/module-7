#include <iostream>
#include <memory>

void printArray(const std::unique_ptr<int[]>& arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i << ": " << arr[i] << std::endl;
    }
}

int main() {
    const int size = 10;
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(size);

    std::cout << "Enter " << size << " numbers: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    printArray(arr, size);

    return 0;
}
