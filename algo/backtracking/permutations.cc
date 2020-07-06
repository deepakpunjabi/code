/* 

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

#include <unordered_set>
#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;

    // seed your solution, to keep recurse method simple
    for (const auto &i : nums) {
        vector<int> curr = {i};
        unordered_set<int> elem = {i};
        recurse(res, nums, curr, elem);
    }

    return res;
}

void recurse(vector<vector<int>> &res, vector<int> &nums, vector<int> &curr, unordered_set<int> &elem) {
    // base condition
    if (curr.size() == nums.size()) {
        res.push_back(curr);
        return;
    }

    for (const auto &j : nums) {
        // don't want to use any element twice
        // as elements are unique value check is fine
        if (elem.find(j) != elem.end()) continue;

        curr.push_back(j);
        elem.insert(j);

        recurse(res, nums, curr, elem);

        // clear previous choice, eg, [1,2] remove 2 to insert 3 ie. [1,3]
        curr.pop_back();
        elem.erase(j);
    }
}
