/*

Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

*/


#include <algorithm>

using namespace std;

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
    int dia = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        height(root);
        return dia - 1;
    }

    int height(TreeNode *root) {
        if (!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);

        // diameter is basically left height + right height 
        dia = max(dia, lh + rh);
        return 1 + max(lh, rh);
    }
};
