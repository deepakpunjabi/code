#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;

    if (!root) return res;

    stack<TreeNode *> s;
    while (true) {
        if (root) {
            // cout << "pushing: " << root->val << endl;
            s.push(root);
            root = root->left;
        } else {
            if (s.empty()) break;
            root = s.top();
            // s.pop();
            if (root->right) {
                if (res.empty()) {
                    root = root->right;

                } else if (res.back() != root->right->val) {
                    root = root->right;
                } else {
                    s.pop();
                    res.push_back(root->val);
                    root = nullptr;
                }
            } else {
                // cout << "doin this shit: " << root->val << endl;
                s.pop();
                res.push_back(root->val);
                root = nullptr;
            }
        }
    }

    return res;
}