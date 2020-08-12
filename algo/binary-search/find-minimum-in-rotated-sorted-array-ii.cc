/* 
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.
The array may contain duplicates.

Example 1:
Input: [1,3,5]
Output: 1

Example 2:
Input: [2,2,2,0,1]
Output: 0

Note:
This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/

#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    if (nums.empty()) return -1;

    return recurse(nums, 0, nums.size() - 1);
}

int recurse(vector<int>& nums, int low, int high) {
    if (low >= high) return nums[low];

    int mid = low + (high - low) / 2;
    if (nums[mid] > nums[mid + 1]) {
        return nums[mid + 1];
    }

    if (nums[low] > nums[mid]) {
        return recurse(nums, low, mid);
    } else if (nums[mid] > nums[high]) {
        return recurse(nums, mid + 1, high);
    } else {
        return min(recurse(nums, low, mid), recurse(nums, mid + 1, high));
    }
}

class IterativeSolution {
   public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[high])
                high = mid;
            else if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high -= 1; // just remove last element as it is highest
        }
        return nums[low];
    }
};
