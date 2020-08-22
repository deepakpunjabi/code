/*
Given an integer array nums, 
find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
 

Constraints:
- You may assume that the array does not change.
- There are many calls to sumRange function.
- 0 <= nums.length <= 10^4
- -10^5 <= nums[i] <= 10^5
- 0 <= i <= j < nums.length
*/

#include <vector>

using namespace std;

/*
    Generate sum dp array which contains sum till ith index
    for any index (i,j) sum is sum[j] - sum[i-1]
*/
class NumArray {
    vector<int> dp;

   public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n, 0);
        dp = tmp;

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            dp[i] = sum;
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return dp[j];
        return dp[j] - dp[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
