/*

    Given a sorted integer array, nums, 
    return the index within nums that the index is equal to the value at that index. 
    If no such index exists, return -1.

    Ex: Given the following nums…
    nums = [0, 4, 8], return 0 (zero occurs at the 0th index).

    Ex: Given the following nums…
    nums = [1, 3, 7, 12], return -1.

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int indexEqualsValue(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        if (i == nums[i]) return i;
    }

    return -1;
}

int main() {
    vector<vector<int>> tc = {
        {},
        {0, 4, 8},
        {1, 2, 3},     // mutliple output possible, go FCFS
        {1, 3, 4, 6},  // -1
        {1, 2, 4, 4, 4},  // duplicate values but sorted
        };           // empty array

    for (auto &i : tc) {
        cout << indexEqualsValue(i) << endl;
    }

    return 0;
}
