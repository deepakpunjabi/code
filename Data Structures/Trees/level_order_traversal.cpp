#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == NULL) {
        return res;
    }

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    vector<int> row;
    while (!q.empty()) {
        TreeNode *tmp = q.front();
        q.pop();

        if (!tmp) {
            res.push_back(row);
            row.resize(0);
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            row.push_back(tmp->val);
            if (tmp->left) q.push(tmp->left);
            if (tmp->left) q.push(tmp->right);
        }
    }

    return res;
}