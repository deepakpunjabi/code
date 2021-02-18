/*
    Given an array of integers, find if the array contains any duplicates.
    Your function should return true if any value appears at least twice in the array, 
    and it should return false if every element is distinct.

    Example 1:
    Input: [1,2,3,1]
    Output: true

    Example 2:
    Input: [1,2,3,4]
    Output: false

    Example 3:
    Input: [1,1,1,3,3,4,3,2,4,2]
    Output: true
*/

#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> elem;

    for (const auto& i : nums) {
        if (elem.find(i) != elem.end()) return true;
        elem.insert(i);
    }

    elem.clear();
    return false;
}

/*
[1,2]
elem = {}

for:
    
    i=1
    elem = {1}
    
    i=2
    elem = {1,2}

false

[1,1]
for
    i=1
    elem={1}
    i=1
    return true
*/
