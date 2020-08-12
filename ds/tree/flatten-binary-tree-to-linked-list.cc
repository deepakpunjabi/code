/*
Given a binary tree, flatten it to a linked list in-place.
For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/

#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode *root) {
    if (!root) return;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();

        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);

        if (!st.empty()) node->right = st.top();
        node->left = nullptr;
    }
}
