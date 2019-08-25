#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;

    if (!root) return res;

    stack<TreeNode*> s;
    while (true) {
        if (root) {
            s.push(root);
            root = root->left;
        } else {
            if (s.empty()) break;
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
    }

    return res;
}