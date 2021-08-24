/* 

Given an array of integers, nums, return the sum of all uniquely occurring elements.

Ex: Given the following nums…
nums = [1, 3, 5, 5, 2], return 6 (1 + 3 + 2).

Ex: Given the following nums…
nums = [4, 4, 2, 3, 3, 2], return 0.

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int sumUniqueElements(vector<int> nums) {
    unordered_set<int> unique;
    int sum = 0;

    for (auto &i : nums) {
        if (unique.find(i) == unique.end()) {
            sum += i;
            unique.insert(i);
        }
    }

    return sum;
}

int main() {
    vector<vector<int>> tc = {
        {},
        {0, 1, 2},        // 3
        {1, 1, 1},        // 1
        {1, 2, 1, 3},     // 6
        {1, 2, 4, 4, 4},  // 7
    };

    for (auto &i : tc) {
        cout << sumUniqueElements(i) << endl;
    }
}
