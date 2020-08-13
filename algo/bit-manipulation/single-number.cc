/*

    Given a non-empty array of integers, every element appears twice except for one. Find that single one.

    Note:
    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

    Example 1:
    Input: [2,2,1]
    Output: 1

    Example 2:
    Input: [4,1,2,1,2]
    Output: 4

*/

#include <numeric>
#include <vector>

using namespace std;

int singleNumber1(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}

// This is better approach
int singleNumber(vector<int>& nums) {
    // ask interviewver what should be returned for such case.
    if (nums.empty()) return 0;

    int result = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        // a ^ b ^ a = b
        result ^= nums[i];
    }
    return result;
}
