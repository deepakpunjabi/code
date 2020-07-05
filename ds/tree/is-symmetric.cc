/* 

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

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
   public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return equal(root->left, root->right);
    }

    bool equal(TreeNode *left, TreeNode *right) {
        // if both are null, you have reached leaf
        if (!left && !right) return true;
        // if either is false, than it is not symmetric
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        return equal(left->right, right->left) && equal(left->left, right->right);
    }
};
