/*

    Given an integer array nums, find the contiguous subarray (containing at least one number) 
    which has the largest sum and return its sum.

    Example 1:
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.

    Example 2:
    Input: nums = [1]
    Output: 1

    Example 3:
    Input: nums = [5,4,-1,7,8]
    Output: 23
    
    Constraints:
    1 <= nums.length <= 3 * 104
    -105 <= nums[i] <= 105
    
    Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, 
    which is more subtle.

*/

#include <vector>
using namespace std;

/* 

    At each index, the max sum can be:
    - the value of the index itself
    - (optimal) sum till previous index + current value

    you also need to keep track of global optimal apart from this.

    approach: keep a array/table maintaining best at each index.
    base case: index-0: max sum that can be obtained is value at nums[0] itself

    you can optimise space by not storing whole table as we only need to access 
    sum for last element at each index

*/
int maxSubArray(vector<int>& nums) {
    int res = nums[0]; // max sum for the array
    int sum = nums[0]; // current sum

    for (int i = 1; i < nums.size(); ++i) {
        sum = max(nums[i], nums[i] + sum);
        res = max(sum, res);
    }

    return res;
}

/*

    TC: O(n)
    SC: O(1)

*/
