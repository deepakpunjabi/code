/* 

    Given a collection of candidate numbers (candidates) and a target number (target), 
    find all unique combinations in candidates where the candidate numbers sums to target.

    Each number in candidates may only be used **once** in the combination.

    Note:
    -   All numbers (including target) will be positive integers.
    -   The solution set must not contain duplicate combinations.
    
    Example 1:
    Input: candidates = [10,1,2,7,6,1,5], target = 8,
    A solution set is:
    [
        [1, 7],
        [1, 2, 5],
        [2, 6],
        [1, 1, 6]
    ]
    
    Example 2:
    Input: candidates = [2,5,2,1,2], target = 5,
    A solution set is:
    [
        [1,2,2],
        [5]
    ]

 */

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> res;
    unordered_set<string> resstr;

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // avoid duplicate results: [1, 7] [7, 1]
        sort(candidates.begin(), candidates.end());

        for (int i = 0; i < candidates.size(); ++i) {
            vector<int> curr = {candidates[i]};
            track(candidates, curr, i, curr[0], target);
        }

        return res;
    }

    void track(vector<int>& candidates, vector<int> curr, int position, int sum, int target) {
        if (sum == target) {
            string s(curr.begin(), curr.end());
            auto it = resstr.find(s);
            if (it == resstr.end()) {
                res.push_back(curr);
                resstr.insert(s);
            }

            return;
        }

        if (candidates[position] + sum > target) return;

        // for combination of candidate + any other element in list
        // not just the next element
        for (int i = position + 1; i < candidates.size(); ++i) {
            vector<int> tmp(curr);
            tmp.push_back(candidates[i]);
            track(candidates, tmp, i, sum + candidates[i], target);
        }
    }
};
