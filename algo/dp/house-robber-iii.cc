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
        unordered_map<TreeNode *, int> cache;
        return recurse(cache, root);
    }

    int recurse(unordered_map<TreeNode *, int> &cache, TreeNode *node) {
        if (!node) return 0;
        if (cache.find(node) != cache.end()) return cache[node];

        // exclude root
        int child = 0;
        child += recurse(cache, node->left);
        child += recurse(cache, node->right);

        // include root
        int grandchild = 0;
        if (node->left) {
            grandchild += recurse(cache, node->left->left) + recurse(cache, node->left->right);
        }
        if (node->right) {
            grandchild += recurse(cache, node->right->left) + recurse(cache, node->right->right);
        }

        cache[node] = max(node->val + grandchild, child);
        return cache[node];
    }
};
