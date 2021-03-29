#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int start = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            swap(nums[i], nums[start]);
            ++start;
        }
    }
}

// without swap!
void moveZeroes(vector<int>& nums) {
    int start = 0;

    // just put the damn non-zero elements in the start
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            nums[start++] = nums[i];
        }
    }

    // set rest of the elements to zero
    for (int i = start; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}

// complicated but understandable logic
void moveZeroes(vector<int>& nums) {
    if (nums.empty()) return;

    int pos = 0;
    for (int i = 1; i < nums.size() and pos < nums.size(); ++i) {
        // swap when pos is 0 but i is not, pos < i is imp!
        if (pos < i && nums[pos] == 0 && nums[i] != 0) {
            swap(nums[pos], nums[i]);
        }
        // increament pos while you can
        while (pos < nums.size() && nums[pos] != 0) {
            ++pos;
        }
    }
}

/*

Given an array nums, write a function to move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

/*
test cases:
[]
[0]
[0 0]
[0 1 0]
*/
