#include <queue>
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

/*

    BFS/Queue based solution
    TC: O(n), size of the tree
    SC: O(n), max n/2 nodes saved in queue or level of the tree
*/
vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) return res;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        vector<int> curr;
        while (size--) {
            TreeNode *tmp = q.front();
            q.pop();

            curr.push_back(tmp->val);

            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        res.push_back(curr);
    }

    return res;
}

/*

    Problem statement:
    Given the root of a binary tree, return the level order traversal of its nodes' values. 
    (i.e., from left to right, level by level).

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]

    Example 2:
    Input: root = [1]
    Output: [[1]]

    Example 3:
    Input: root = []
    Output: []
    
    Constraints:
    - The number of nodes in the tree is in the range [0, 2000].
    - -1000 <= Node.val <= 1000

*/
