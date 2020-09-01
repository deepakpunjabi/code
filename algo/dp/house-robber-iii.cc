/*

The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called the "root." 
Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1
Output: 7 

Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

*/

#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    including node = node_val + optimal at level-2 
    excluding node = optimal at level -1
*/
class Memoization {
   public:
    int rob(TreeNode *root) {
        unordered_map<TreeNode *, int> dp;
        return recurse(dp, root);
    }

    int recurse(unordered_map<TreeNode *, int> &dp, TreeNode *node) {
        if (!node) return 0;
        if (dp.find(node) != dp.end()) return dp[node];

        // exclude root
        int child = 0;
        child += recurse(dp, node->left);
        child += recurse(dp, node->right);

        // include root
        int grandchild = 0;
        if (node->left) {
            grandchild += recurse(dp, node->left->left) + recurse(dp, node->left->right);
        }
        if (node->right) {
            grandchild += recurse(dp, node->right->left) + recurse(dp, node->right->right);
        }

        dp[node] = max(node->val + grandchild, child);
        return dp[node];
    }
};
