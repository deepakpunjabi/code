/*

    Given a binary array, bits, 
    return the maximum number of contiguous ones within the array.

    Ex: Given the following bits…
    bits = [1, 0, 1, 1], return 2.

    Ex: Given the following bits…
    bits = [0, 0, 0], return 0.

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int binaryBits(vector<int> &nums) {
    if (nums.empty()) return 0;

    int res = 0;
    int currmax = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i]) {
            ++currmax;
        } else {
            res = max(res, currmax);
            currmax = 0;
        }
    }

    return max(res, currmax);
}

int main() {
    vector<vector<int>> tc = {
        {},
        
        {0},
        {1},

        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1},
        
        {0, 0, 1},
        {1, 0, 1},

        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 1, 1},
        
        {0, 0, 1, 1, 0, 0, 1, 1, 1, 0},
        
    };

    for (auto &i : tc) {
        cout << i.size() << " --> " << binaryBits(i) << endl;
    }

    return 0;
}
