/*
Given the root of a binary tree, return the number of uni-value subtrees.
A uni-value subtree means all nodes of the subtree have the same value.

Example 1:
Input: root = [5,1,5,5,5,null,5]
Output: 4

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [5,5,5,5,5,null,5]
Output: 6

Constraints:
The number of the node in the tree will be in the range [0, 1000].
-1000 <= Node.val <= 1000
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int count = 0;

   public:
    int countUnivalSubtrees(TreeNode *root) {
        if (!root) return 0;

        recurse(root);
        return count;
    }

    bool recurse(TreeNode *root) {
        if (!root->left && !root->right) {
            count++;
            return true;
        }

        bool res = true;
        if (root->left) {
            bool left = recurse(root->left);
            res = res and left and root->left->val == root->val;
        }
        if (root->right) {
            bool right = recurse(root->right);
            res = res and right and root->right->val == root->val;
        }

        if (res) {
            count++;
        }

        return res;
    }
};
