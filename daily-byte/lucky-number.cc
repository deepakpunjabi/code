/*

    Given an array, nums, every value appears twice except for one which only appears once. 
    The value that only appears once is the lucky number. Return the lucky number.

    Ex: Given the following nums…
    nums = [1, 2, 1], return 2.

    Ex: Given the following nums…
    nums = [1, 3, 1, 2, 2], return 3.

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
