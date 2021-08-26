/*

    Given an array of integers nums which is sorted in ascending order, and an integer target, 
    write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
    You must write an algorithm with O(log n) runtime complexity.

    Example 1:
    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
    Explanation: 9 exists in nums and its index is 4

    Example 2:
    Input: nums = [-1,0,3,5,9,12], target = 2
    Output: -1
    Explanation: 2 does not exist in nums so return -1
    
    Constraints:
    - 1 <= nums.length <= 104
    - -104 < nums[i], target < 104
    - All the integers in nums are unique.
    - nums is sorted in ascending order.

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

// tc: O(logn)
// sc: o(1)

/* 

nums = [-1,0,3,5,9,12], target = 9
low = 0
high = 5

while:
    mid = 2
    nums[2] = 3
    3 < 5
    
    low = 3
    high = 5

    mid = 4
    nums[4] = 9
    retun 4 
    
*/

/* 

nums = [-1,0,3,5,9,12], target = 2
low = 0
high = 5

while:
    mid = 2
    nums[2] = 3
    3 > 2

    low = 0
    high = 1

    mid = 0
    nums[0] = -1
    -1 < 2

    low = 1
    high = 1
    mid = 1
    nums[1] = 0
    0 < 2

    low = 2
    high = 1
    return -1 

*/
