#include <iostream>
#include <vector>
#include <functional>
#include <cassert>

int fold(const std::function<int(int, int)>& function, const std::vector<int>& nums);
int add(int a, int b);
int multiply(int a, int b);
int subtract(int a, int b);
void test_fold();

int main() {
    test_fold();

    return 0;
}

int fold(const std::function<int(int, int)>& function, const std::vector<int>& nums) {
    // Base case
    if (nums.size() == 1) {
        return nums[0];
    }

    // Create a new vector containing everything except the first element
    std::vector<int> restOfVector(nums.begin() + 1, nums.end());

    // Recursive case
    return function(nums[0], fold(function, restOfVector));
}

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void test_fold() {
    std::vector<int> numbers = { 1, 2, 3, 4 };

    assert(fold(add, numbers) == 10);
    assert(fold(multiply, numbers) == 24);
    assert(fold(subtract, numbers) == -2);
    assert(fold(max, numbers) == 4);

    std::cout << "test_fold PASSED\n";
}