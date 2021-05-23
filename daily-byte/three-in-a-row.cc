/*

    Given an integer array, nums, 
    return true if there are three consecutive odd values within nums, otherwise, return false.

    Ex: Given the following nums…
    nums = [1, 2, 3, 4, 5], return false.

    Ex: Given the following nums…
    nums = [1, 3, 4, 2, 3, 9, 15], return true.

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> tc = {
        {},
        {0, 4, 8},
        {1, 2, 3},        // mutliple output possible, go FCFS
        {1, 3, 4, 6},     // -1
        {1, 2, 4, 4, 4},  // duplicate values but sorted
    };                    // empty array

    for (auto &i : tc) {
        // cout << indexEqualsValue(i) << endl;
    }

    return 0;
}
