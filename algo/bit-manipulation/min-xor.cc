// https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/minimum-and-xor-or-6a05bbd4/

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int minXor(vector<int> &nums) {
    int minimum = INT_MAX;

    for (int i = 1; i < nums.size(); ++i) {
        minimum = min(minimum, nums[i] ^ nums[i - 1]);
        if (minimum == 0) {
            return 0;
        }
    }

    return minimum;
}

int main() {
    int T;
    cin >> T;

    int size;
    int num;
    for (int t = 0; t < T; ++t) {
        cin >> size;

        vector<int> nums(size);
        for (int i = 0; i < size; ++i) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());
        cout << minXor(nums) << endl;
    }
}
