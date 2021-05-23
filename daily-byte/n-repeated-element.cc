/*

    You are given an integer array, nums, which contains 2N elements. 
    Within nums there are N + 1 unique elements and a specific element occurs N times. 
    Return the element within nums that appears N times.

    Ex: Given the following nums…
    nums = [3, 3, 5, 1], return 3.

    Ex: Given the following nums…
    nums = [4, 2, 4, 5, 4, 1], return 4.

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
