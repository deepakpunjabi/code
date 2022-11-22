/*

    Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, 
    return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
    Two nodes of a binary tree are cousins if they have the same depth with different parents.
    Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

    Example 1:
    Input: root = [1,2,3,4], x = 4, y = 3
    Output: false

    Example 2:
    Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
    Output: true

    Example 3:
    Input: root = [1,2,3,null,4], x = 2, y = 3
    Output: false

    Constraints:
    The number of nodes in the tree is in the range [2, 100].
    1 <= Node.val <= 100
    Each node has a unique value.
    x != y
    x and y are exist in the tree.

*/

#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isCousins(TreeNode* root, int x, int y) {
    int dx = depth(root, x);
    int dy = depth(root, y);

    TreeNode* px = parent(root, nullptr, x);
    TreeNode* py = parent(root, nullptr, y);

    return dx == dy && px != py;
}

int depth(TreeNode* root, int x) {
    if (!root) return -1;

    if (root->val == x) {
        return 1;
    }

    int dx = depth(root->left, x);
    int dy = depth(root->right, x);

    int d = max(dx, dy);
    return d == -1 ? d : d + 1;
}

TreeNode* parent(TreeNode* root, TreeNode* prev, int x) {
    if (!root) return nullptr;

    if (root->val == x) return prev;

    TreeNode* px = parent(root->left, root, x);
    TreeNode* py = parent(root->right, root, x);

    return px == nullptr ? py : px;
}
