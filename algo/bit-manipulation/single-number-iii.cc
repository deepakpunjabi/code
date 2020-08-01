/* 
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once.

Example:
Input:  [1,2,1,3,2,5]
Output: [3,5]

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

#include <vector>
#include <unordered_set>

using namespace std;

// this should be done xor way.
// first get xor of array, so final result will be xor of 2 unique elements
// than find the set bits which will mean bits are different in both numbers
vector<int> singleNumber(vector<int> &nums) {
    unordered_set<int> un;
    for (const auto &i : nums) {
        if (un.find(i) != un.end()) {
            un.erase(i);
        } else {
            un.insert(i);
        }
    }
    vector<int> res;
    for (const auto &i : un) {
        res.push_back(i);
    }
    return res;
}
