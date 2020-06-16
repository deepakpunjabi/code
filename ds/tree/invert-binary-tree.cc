/*

invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

/**
 * Definition for a binary tree node.
 * 
 */

#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class InvertBinaryTree {
   public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return root;
        // trick is to swap pointer instead of data.
        // otherwise you'll start having problem at second level.
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

/*
Complexity Analysis

Since each node in the tree is visited only once, the time complexity is O(n), 
where nn is the number of nodes in the tree. We cannot do better than that, 
since at the very least we have to visit each node to invert it.

Because of recursion, O(h) function calls will be placed on the stack in the worst case, 
where hh is the height of the tree. Because h\in O(n) h ∈ O(n), the space complexity is O(n).
*/

//  Use queue based iterative approach
class InvertBinaryTreeIterative {
   public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return root;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *node = q.front();
            // cpp q pop doesn't return the element
            q.pop();
            swap(node->left, node->right);
            // push in left->right order as we have already swapped
            // otherwise swap in right->left order
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return root;
    }
};

/*

Complexity Analysis:
Time: Each element is visited once, hence O(n)
Space: queue can contain up to half + 1 of all the nodes(or one level of the tree), hence O(n)
*/
