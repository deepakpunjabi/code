/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:
Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

Note:
There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <vector>
using namespace std;

/* 
    start with 1 length subsequence at each point
    if j < i than subseq[i] must be 1 + subseq[j]
    maintain max seen so far
*/
class DP {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;

        vector<int> dp(n, 1);
        int max_len = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
                max_len = max(max_len, dp[i]);
            }
        }

        return max_len;
    }
};
