/* 
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
 */

#include <vector>

using namespace std;

class SearchRecursive {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        return searchBinary(nums, low, high, target);
    }

    int searchBinary(vector<int>& a, int low, int high, int target) {
        if (low > high) return -1;

        int mid = low + (high - low) / 2;
        if (a[mid] == target) {
            return mid;
        }
        // left half is sorted and taregt lies in left
        else if (a[low] < a[mid] && a[mid] > target && target > a[low]) {
            return searchBinary(a, low, mid - 1, target);
        }
        // right half is sorted and target lies in right
        else if (a[mid] < a[high] && a[mid] < target && target < a[high]) {
            return searchBinary(a, mid + 1, high, target);
        }
        // try out both left and right halves
        else {
            int res = searchBinary(a, low, mid - 1, target);
            if (res != -1) return res;
            return searchBinary(a, mid + 1, high, target);
        }

        // still did not find
        return -1;
    }
};

class SearchIteratively {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[low] <= nums[mid]) {
                // target can be nums[low]
                if (target < nums[mid] && target >= nums[low]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (nums[mid] <= nums[high]) {
                // target can be nums[high]
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
