/*

    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:
    - The left subtree of a node contains only nodes with keys less than the node's key.
    - The right subtree of a node contains only nodes with keys greater than the node's key.
    - Both the left and right subtrees must also be binary search trees.

*/

#include <climits>
#include <cstdio>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class LogicalSolution {
   public:
    bool isValidBST(TreeNode* root) {
        return checkValidNode(root, INT_MIN, INT_MAX);  // min and max values here shouldn't be allowed in node val.
    }

    bool checkValidNode(TreeNode* root, int low, int high) {
        if (!root) return true;
        if (root->val <= low or root->val >= high) return false;

        return checkValidNode(root->left, low, root->val) and checkValidNode(root->right, root->val, high);
    }
};

// instead of using int* you can pass NULL as well
class NullptrSolution {
   public:
    bool isValidBST(TreeNode* root) {
        return checkValidNode(root, nullptr, nullptr);
    }

    bool checkValidNode(TreeNode* root, int* low, int* high) {
        if (!root) return true;
        if ((low != nullptr and root->val <= *low) or (high != nullptr and root->val >= *high)) return false;

        return checkValidNode(root->left, low, &root->val) and checkValidNode(root->right, &root->val, high);
    }
};

class BestSolution {
   public:
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }

    bool validate(TreeNode* root, TreeNode* low, TreeNode* high) {
        if (!root) return true;

        if ((low != nullptr and root->val <= low->val) or (high != nullptr and root->val >= high->val)) {
            return false;
        }

        return validate(root->right, root, high) and validate(root->left, low, root);
    }
};

// no-none-sense solution
class InorderSolution {
   public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return traverseAndCheck(root, prev);
    }

    bool traverseAndCheck(TreeNode* root, TreeNode*& prev) {
        if (!root) return true;

        if (traverseAndCheck(root->left, prev)) return false;
        if (prev and prev->val >= root->val) return false;
        prev = root;

        return traverseAndCheck(root->right, prev);
    }
};
