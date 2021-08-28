/*

    Given an integer array nums sorted in non-decreasing order, 
    return an array of the squares of each number sorted in non-decreasing order.

    Example 1:
    Input: nums = [-4,-1,0,3,10]
    Output: [0,1,9,16,100]
    Explanation: After squaring, the array becomes [16,1,0,9,100].
    After sorting, it becomes [0,1,9,16,100].

    Example 2:
    Input: nums = [-7,-3,2,3,11]
    Output: [4,9,9,49,121]
    
    Constraints:
    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in non-decreasing order.
    
    Follow up: Squaring each element and sorting the new array is very trivial, 
    could you find an O(n) solution using a different approach?

*/

#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// the highest value in the result will come either from leftmost index or the rightmost index
vector<int> sortedSquares(vector<int>& nums) {
    if (nums.empty()) return nums;

    vector<int> res(nums.size());
    int low = 0;
    int high = nums.size() - 1;
    int pos = nums.size() - 1;
    while (low <= high) {
        if (abs(nums[low]) > abs(nums[high])) {
            res[pos] = nums[low] * nums[low];
            ++low;
        } else {
            res[pos] = nums[high] * nums[high];
            --high;
        }
        --pos;
    }

    return res;
}

// [-4, -1, 0, 3, 10]
// low = 0;
// high = 4;
// pos = 4

// while:
// 0 < 4
// abs(-4) > abs(10)

// res(4) = 100
// high = 3
// pos = 3

// 4 3
// res[3] = 16
// low = 1
// pos = 2

// 1 9
// res[2] = 9
// high = 2
// low = 1
// pos = 1

// res[1] = 1
// low = 2
// high = 2
// pos = 0

// res
