/*
    Given an array of integers and an integer k, 
    find out whether there are two distinct indices i and j in the array such that 
    nums[i] = nums[j] and the absolute difference between i and j is at most k.

    Example 1:
    Input: nums = [1,2,3,1], k = 3
    Output: true

    Example 2:
    Input: nums = [1,0,1,1], k = 1
    Output: true

    Example 3:
    Input: nums = [1,2,3,1,2,3], k = 2
    Output: false
*/

#include <unordered_map>
#include <vector>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> mapping;

    for (int i = 0; i < nums.size(); ++i) {
        if (mapping.find(nums[i]) != mapping.end() && abs(mapping[nums[i]] - i) <= k) return true;

        mapping[nums[i]] = i;
    }

    return false;
}
