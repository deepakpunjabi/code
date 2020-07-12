/* 

    Given a set of distinct integers, nums, return all possible subsets (the power set).
    Note: The solution set must not contain duplicate subsets.

    Example:
    Input: nums = [1,2,3]
    Output:
    [
    [3],
    [1],
    [2],
    [1,2,3],
    [1,3],
    [2,3],
    [1,2],
    []
    ]

*/

#include <vector>

using namespace std;

class Generic {
   public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        res.push_back({});

        for (int len = 0; len < nums.size(); ++len) {
            vector<int> curr;
            recurse(res, curr, nums, len + 1, 0);
        }

        return res;
    }

    void recurse(vector<vector<int>> &res, vector<int> &curr, vector<int> &nums, int len, int pos) {
        if (curr.size() == len) {
            res.push_back(curr);
            return;
        }

        // start selecting candidates from pos to not have repeated elements
        for (int i = pos; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            recurse(res, curr, nums, len, i + 1);
            curr.pop_back();
        }
    }
};

class Best {
   public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;

        vector<int> curr;
        recurse(res, curr, nums, 0);

        return res;
    }

    void recurse(vector<vector<int>> &res, vector<int> &curr, vector<int> &nums, int pos) {
        // there is no need for base condition as you want all possible answers!
        res.push_back(curr);

        // start selecting candidates from pos to not have repeated elements
        for (int i = pos; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            recurse(res, curr, nums, i + 1);
            curr.pop_back();
        }
    }
};

/* 
    Time Complexity: O(2^n), where n is the size of nums, total numbers
    Space Complexity: O(n), as we will store lagest number as nums itself
*/
