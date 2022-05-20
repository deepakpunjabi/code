
#include <vector>
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

class Solution {
   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recurse(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    // Here we are focusing on the left width rather than the right width.
    // Moreover, all parameters are referred wrt to width.
    // so equations are in the form of: (low + width)
    TreeNode* recurse(vector<int>& inorder, int l1, int h1, vector<int>& postorder, int l2, int h2) {
        if (l1 > h1 or l2 > h2) {
            return nullptr;
        }

        int val = postorder[h2];
        TreeNode* root = new TreeNode(val);

        auto it = find(inorder.begin(), inorder.end(), val);
        if (it == inorder.end()) {
            return nullptr;
        }
        int width = (it - inorder.begin()) - l1;

        root->left = recurse(inorder, l1, l1 + width - 1, postorder, l2, l2 + width - 1);
        root->right = recurse(inorder, l1 + width + 1, h1, postorder, l2 + width, h2 - 1);

        return root;
    }
};
