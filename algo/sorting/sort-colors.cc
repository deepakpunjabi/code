/* 

    Given an array with n objects colored red, white or blue, sort them in-place 
    so that objects of the same color are adjacent, with the colors in the order red, white and blue.
    Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
    Note: You are not suppose to use the library's sort function for this problem.

    Example:
    Input: [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

    Follow up:
    A rather straight forward solution is a two-pass algorithm using counting sort.
    First, iterate the array counting number of 0's, 1's, and 2's, 
    then overwrite array with total number of 0's, then 1's and followed by 2's.
    Could you come up with a one-pass algorithm using only constant space?

*/

#include <vector>

using namespace std;

/* 

    This implementation is inspired from quick sort partition method.
    We are shifting 2's to the high side and 1's to low side. 
    Partition index is updated when 1 is encountered or swapped with 0.

    Test cases:
    - []
    - [0,1,2]
    - [2,1,0]
    - [1,0,2]
    - [1,2,0]
    - [1,2,0,0], [1,2,2,0]

    Time complexity: O(n), as we are doing 1 pass over array, swap is o(1)
    Space complexity: O(1), as we are not creating any dynamic memory

    Extra:
    - This problem can be easily solved using counting sort. Keep 3 vars, one, two & three.
      Stores counts of each in respective variable. Regenerate array using counts.
    - We can also solve it in 2 pass, one to find index of last 1, 
      and second pass to partition array around around this index. 

*/
void sortColors(vector<int>& nums) {
    if (nums.empty()) return;

    int pivot = 0;
    int low = 0;
    int high = nums.size() - 1;

    while (pivot <= high) {
        if (nums[pivot] == 2) {
            swap(nums[pivot], nums[high]);
            --high;
        } else if (nums[pivot] == 0) {
            swap(nums[pivot], nums[low]);
            ++low;
            ++pivot;
        } else {
            ++pivot;
        }
    }
}
