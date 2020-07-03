// Given a binary tree, return the postorder traversal of its nodes' values.

#include <stack>
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

/*

Use 2 stacks s1 and s2. push root into first.
pop and push into s2. If there are left and right, push them in s1.
repeat.

*/
vector<int> postorderTraversalIterative(TreeNode *root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode *> st1;
    stack<TreeNode *> st2;

    st1.push(root);

    while (!st1.empty()) {
        TreeNode *tmp = st1.top();
        st1.pop();

        st2.push(tmp);

        if (tmp->left) st1.push(tmp->left);
        if (tmp->right) st1.push(tmp->right);
    }

    while (!st2.empty()) {
        TreeNode *tmp = st2.top();
        st2.pop();
        res.push_back(tmp->val);
    }

    return res;
}

vector<int> postorderTraversalRecursive(TreeNode *root) {
    vector<int> res;
    postorder(root, res);
    return res;
}

void postorder(TreeNode *root, vector<int> &res) {
    if (!root) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}
