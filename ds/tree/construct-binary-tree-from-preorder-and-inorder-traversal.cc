/*
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.

For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recurse(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* recurse(vector<int>& preorder, int p1, int p2, vector<int>& inorder, int i1, int i2) {
        if (p1 > p2 || i1 > i2) return nullptr;
        if (p1 == p2) return new TreeNode(preorder[p1]);

        int node = preorder[p1];

        // find position of root in inorder
        int i;
        for (i = i1; i < i2; ++i) {
            if (inorder[i] == node) break;
        }
        int left_width = i - i1;  // how many nodes are there in the left or root

        TreeNode* res = new TreeNode(node);
        res->left = recurse(preorder, p1 + 1, p1 + left_width, inorder, i1, i - 1);
        res->right = recurse(preorder, p1 + left_width + 1, p2, inorder, i + 1, i2);

        return res;
    }
};
