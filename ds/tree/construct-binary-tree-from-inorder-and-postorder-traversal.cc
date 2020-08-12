
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recurse(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* recurse(vector<int>& postorder, int p1, int p2, vector<int>& inorder, int i1, int i2) {
        if (p1 > p2 || i1 > i2) return nullptr;

        TreeNode* node = new TreeNode(postorder[p2]);
        int right_width, i;
        for (i = i1; i <= i2; ++i) {
            if (inorder[i] == postorder[p2]) {
                right_width = i2 - i;
                break;
            }
        }
        node->left = recurse(postorder, p1, p2 - right_width - 1, inorder, i1, i - 1);
        node->right = recurse(postorder, p2 - right_width, p2 - 1, inorder, i + 1, i2);
        return node;
    }
};
