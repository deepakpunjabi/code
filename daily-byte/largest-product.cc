/*

    Given a non-negative integer array, nums, 
    return the maximum product you can create with two separate indices i and j.
    Note: You may assume the product will not overflow.

    Ex: Given the following nums…
    nums = [4, 2, 5, 3], return 20 (5 * 4).

    Ex: Given the following nums…
    nums = [6, 2, 4, 3], return 24.

*/

#include <iostream>
#include <vector>
using namespace std;

int largestProduct(vector<int> nums) {
    if (nums.size() < 2) return -1;

    int large = 0;
    int largest = 0;

    for (const auto &i : nums) {
        if (i > large) {
            large = i;
        }
        if (i > largest) {
            swap(large, largest);
        }
    }

    return large * largest;
}

int main() {
    vector<vector<int>> tc = {
        {1, 2, 3},     // 6
        {3, 2, 1},     // 6
        {2, 1, 3},     // 6
        {3, 2, 1, 4},  // 12
        {0},           // -1
        {0, 1},        // 0
        {4, 0, 1}};    // 4

    for (auto &i : tc) {
        cout << largestProduct(i) << endl;
    }

    return 0;
}
