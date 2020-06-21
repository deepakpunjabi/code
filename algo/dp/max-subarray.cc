#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int csum = nums[0];
    int sum = csum;

    for (int i = 1; i < nums.size(); ++i) {
        // max nums, csum + num
        // max sum can be this element or sum till now + this element
        csum = max(nums[i], csum + nums[i]);
        sum = max(sum, csum);
    }

    return sum;
}

int maxSubArrayIndex(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int csum = nums[0];
    int sum = csum;

    int start = 0, end = 0;

    for (int i = 1; i < nums.size(); ++i) {
        // max nums, csum + num
        // max sum can be this element or sum till now + this element
        csum = csum + nums[i];
        if (nums[i] > csum) {
            csum = nums[i];
            start = i;
            
        }
        csum = max(nums[i], csum + nums[i]);
        sum = max(sum, csum);
    }

    return sum;
}

int maxSubArray1(vector<int>& nums) {
    int csum = INT_MIN;
    int sum = csum;

    for (const auto& i : nums) {
        // signed integer overflow: -2147483648 + -2 for input [-2]
        csum = max(i, csum + i);
        sum = max(csum, sum);
    }

    return sum;
}

int main() {
    vector<int> v = {3, -2, -1, 2, 3};
    cout << maxSubArray(v) << endl;
}
