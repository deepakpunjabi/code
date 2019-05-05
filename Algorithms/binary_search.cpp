#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      return binary_search(nums, 0, nums.size()-1, target);
    }
  
    int binary_search(vector<int>& nums, int left, int right, int target) {
      if (left > right) {
        return -1;
      }
      
      int mid = left + (right-left)/2;
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[mid] > target) {
        return binary_search(nums, left, mid-1, target);
      }
      return binary_search(nums, mid+1, right, target);
    }
};