// https://leetcode.com/problems/two-sum

// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <unordered_map>
#include <vector>
using namespace std;

// simpler codign style for maps, avoid iterators
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mapping;

    for (int i = 0; i < nums.size(); ++i) {
        if (mapping.find(target - nums[i]) != mapping.end()) {
            return vector<int>{mapping[target - nums[i]], i};
        } else {
            mapping[nums[i]] = i;
        }
    }

    return vector<int>{};
}

// older
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = m.find(target - nums[i]);
            if (it != m.end()) {
                // vector is object, it doesn't require new
                // same as int i doesn't require new
                return vector<int>{it->second, i};
            } else {
                m.emplace(nums[i], i);
            }
        }
        // redundant
        return vector<int>{};
    }
};
