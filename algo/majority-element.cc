/*

Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty 
and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2

*/

#include <vector>

using namespace std;

// Boyer-Moore algorithm
// https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
int majorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (const auto& i : nums) {
        if (!count) {
            candidate = i;
        }
        if (candidate == i) {
            ++count;
        } else {
            --count;
        }
    }

    return candidate;
}
