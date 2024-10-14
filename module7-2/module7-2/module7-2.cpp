#include <iostream>
#include <memory>
#include <limits>


void calculateSum(const std::weak_ptr<int[]>& weakPtr, int size) {
    if (auto sharedPtr = weakPtr.lock()) {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += sharedPtr[i];
        }
        std::cout << "Sum of all elements: " << sum << std::endl;
    }
    else {
        std::cout << "Failed to lock the shared_ptr." << std::endl;
    }
}

std::pair<int, int> findMinMax(const std::shared_ptr<int[]>& sharedPtr, int size) {
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();

    for (int i = 0; i < size; ++i) {
        if (sharedPtr[i] < min) min = sharedPtr[i];
        if (sharedPtr[i] > max) max = sharedPtr[i];
    }
    return { max, min };
}

int main() {
    
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::shared_ptr<int[]> arr = std::make_shared<int[]>(n);

    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::weak_ptr<int[]> weakArr = arr;

    calculateSum(weakArr, n);
    auto [max, min] = findMinMax(arr, n);
    std::cout << "Max: " << max << ", Min: " << min << std::endl;

    return 0;
}

