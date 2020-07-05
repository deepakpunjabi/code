/* 

    Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
    find all unique combinations in candidates where the candidate numbers sums to target.

    The same repeated number may be chosen from candidates unlimited number of times.

    Note:
    -   All numbers (including target) will be positive integers.
    -   The solution set must not contain duplicate combinations.

    Example 1:
    Input: candidates = [2,3,6,7], target = 7,
    A solution set is:
    [
        [7],
        [2,2,3]
    ]

    Example 2:
    Input: candidates = [2,3,5], target = 8,
    A solution set is:
    [
        [2,2,2,2],
        [2,3,3],
        [3,5]
    ] 

*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> res;
    unordered_set<string> resstr;

   public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // repeat smaller numbers first
        // avoid duplicate results: [1, 7] [7, 1]
        sort(candidates.begin(), candidates.end());

        // recurse for every position as start candidate
        for (int i = 0; i < candidates.size(); ++i) {
            vector<int> curr = {candidates[i]};
            // printf("master calling track(%d, %d, %d, %d)\n", curr[0], i, curr[0], target);
            track(candidates, curr, i, curr[0], target);
        }

        return res;
    }

    void track(vector<int> &candidates, vector<int> curr, int position, int sum, int target) {
        if (sum == target) {
            res.push_back(curr);
            return;
        }

        if (candidates[position] + sum > target) return;

        // for combination of candidate + any other element in list
        // not just the next element
        for (int i = position; i < candidates.size(); ++i) {
            vector<int> tmp(curr);
            tmp.push_back(candidates[i]);
            // printf("--- calling track(%d, %d, %d, %d)\n", tmp[0], i, sum + candidates[i], target);
            track(candidates, tmp, i, sum + candidates[i], target);
        }
    }

    string print(vector<vector<int>> &a) {
        string s("[");
        for (const auto &i : a) {
            s += '[';
            for (const auto &j : i) {
                s += j + '0';
                s += ", ";
            }
            s[s.size() - 2] = ']';
            s[s.size() - 1] = ',';
        }
        s[s.size() - 1] = ']';
        return s;
    }
};

int main() {
    Solution s;
    
    // vector<int> candidates = {2, 3, 5};
    // target = 7

    vector<int> c = {8, 7, 4, 3};
    int target = 11;

    vector<vector<int>> result = s.combinationSum(c, target);
    cout << s.print(result) << endl;
}
