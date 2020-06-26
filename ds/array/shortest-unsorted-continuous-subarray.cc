/*

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

*/


#include <vector>

using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    int sorted = true;

    // min and max can lie in between unsorted array
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] > nums[i]) {
            sorted = false;
        }
        if (!sorted) {
            min_val = min(min_val, nums[i]);
        }
    }

    sorted = true;
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] > nums[i + 1]) {
            sorted = false;
        }
        if (!sorted) {
            // as we are comparing ith position we need to make sure we iterate over every value including 0
            // other solve i > 0; nums[i-1] > nums[i]; max(max_val, nums[i-1])
            max_val = max(max_val, nums[i]);
        }
    }
    
    // find correct positions for min and max
    int low, high;
    for (low = 0; low < nums.size(); ++low) {
        if (nums[low] > min_val) break;
    }
    for (high = nums.size() - 1; high >= 0; --high) {
        if (nums[high] < max_val) break;
    }

    if (low > high) return 0;

    return high - low + 1;
}
