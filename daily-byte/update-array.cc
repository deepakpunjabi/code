/*

    Given an integer array, nums, 
    replace each element with the largest value that occurs to the right of it and return the array.
    Note: The rightmost element should be replaced with -1.

    Ex: Given the following nums…
    nums = [5, 2, 3], return [3, 3, -1].

    Ex: Given the following nums…
    nums = [10, 2, 5, 8, 9], return [9,9,9,9,-1].

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> updateArray(vector<int> &nums) {
    vector<int> res;

    if (nums.empty()) return res;

    int n = nums.size();
    res.resize(n, 0);

    int max = nums[n - 1];
    res[n - 1] = -1;

    for (int i = n - 2; i >= 0; --i) {
        res[i] = max;
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    return res;
}

int main() {
    // imagine only positive integers for this example
    // negatives are not making sense
    vector<vector<int>> tc = {
        {},  // {}

        {0},  // {-1}

        {0, 1},  // {1, -1}
        {1, 0},  // {0,-1}
        {1, 5},  // {5, -1}

        {1, 2, 3},  // {3,3,-1}
        {3, 2, 1},  // {2,1,-1}
    };

    for (auto &i : tc) {
        cout << "[";
        for (auto &k : i) {
            cout << k << ", ";
        }
        cout << "]";
        cout << "\t--->\t";

        auto res = updateArray(i);

        cout << "[";
        for (auto &j : res) {
            cout << j << ", ";
        }
        cout << "]";
        cout << endl;
    }

    return 0;
}
