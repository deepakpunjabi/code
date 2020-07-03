// Given a binary tree, return the preorder traversal of its nodes' values.

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    return preorder(root, res);
}

vector<int> preorder(TreeNode *root, vector<int> &res) {
    if (!root) return res;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
    return res;
}
