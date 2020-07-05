/* 

    Given an array of integers nums sorted in ascending order,
    find the starting and ending position of a given target value.

    Your algorithm's runtime complexity must be in the order of O(log n).
    If the target is not found in the array, return [-1, -1].

    Example 1:
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]
    
    Example 2:
    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
    

    Constraints:
    -   0 <= nums.length <= 10^5
    -   -10^9 <= nums[i] <= 10^9
    -   nums is a non decreasing array.
    -   -10^9 <= target <= 10^9

 */

#include <vector>

using namespace std;

class FindBinaryWithLinear {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int res = search(nums, 0, nums.size() - 1, target);
        if (res == -1) {
            return vector<int>{-1, -1};
        }
        // return expandBinary(nums, low, high, target, left);

        int low = res;
        int high = res;
        while (low >= 0 && nums[low] == target) {
            --low;
        }
        while (high < nums.size() && nums[high] == target) {
            ++high;
        }
        return vector<int>{low + 1, high - 1};
    }

    int search(vector<int>& nums, int low, int high, int target) {
        if (low > high) return -1;
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            return search(nums, mid + 1, high, target);
        } else {
            return search(nums, low, mid - 1, target);
        }
    }

    // int expandBinary(vector<int> &nums, int low, int high, )
};

class FinaBinary {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{searchLeft(nums, target), searchRight(nums, target)};
    }

    int searchLeft(vector<int>& nums, int target) {
        int index = -1;

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            if (nums[mid] == target) {
                index = mid;
            }
        }

        return index;
    }

    int searchRight(vector<int>& nums, int target) {
        int index = -1;

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            if (nums[mid] == target) {
                index = mid;
            }
        }

        return index;
    }
};
