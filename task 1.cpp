#include <iostream>
#include <vector>

// Function to calculate the summation of an integer array
int summation(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

// Function to calculate the maximum of an integer array
int maximum(const std::vector<int>& arr) {
    int max = arr[0];
    for (int num : arr) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

int main() {
    // Get the number of integers from the user
    int n;
    std::cout << "Enter the number of integers: ";
    std::cin >> n;

    // Check if the input is valid
    if (n < 0 || n > 1000) {
        std::cout << "Error: invalid number of integers.\n";
        return 1;
    }

    // Initialize an array of length n
    std::vector<int> arr(n);

    // Get the integers from the user
    for (int i = 0; i < n; i++) {
        std::cout << "Enter integer " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    // Call the summation and maximum functions and display their outputs
    std::cout << "Summation: " << summation(arr) << "\n";
    std::cout << "Maximum: " << maximum(arr) << "\n";

    return 0;
}