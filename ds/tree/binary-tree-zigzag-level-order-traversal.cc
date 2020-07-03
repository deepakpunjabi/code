/*

Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

*/

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

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> zigzag;
    if (!root) return zigzag;

    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

    bool left(true);

    vector<int> row;

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        if (left) {
            while (!s1.empty()) {
                TreeNode *tmp = s1.top();
                s1.pop();

                row.push_back(tmp->val);

                if (tmp->left) s2.push(tmp->left);
                if (tmp->right) s2.push(tmp->right);
            }
            left = false;
            zigzag.push_back(row);
            row.clear();
        } else {
            while (!s2.empty()) {
                TreeNode *tmp = s2.top();
                s2.pop();

                row.push_back(tmp->val);

                if (tmp->right) s1.push(tmp->right);
                if (tmp->left) s1.push(tmp->left);
            }
            left = true;
            zigzag.push_back(row);
            row.clear();
        }
    }
    return zigzag;
}

/*
time complexity: O(n), as we are travesing each node once
space complexity O(n), as we will store at most half of the nodes in a level
*/
