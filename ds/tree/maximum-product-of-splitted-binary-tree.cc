/*

    Given the root of a binary tree, 
    split the binary tree into two subtrees by removing one edge such that the maxProd of the totalSums of the subtrees is maximized.

    Return the maximum maxProd of the totalSums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
    Note that you need to maximize the answer before taking the mod and not after taking it.

    Example 1:
    Input: root = [1,2,3,4,5,6]
    Output: 110
    Explanation: Remove the red edge and get 2 binary trees with totalSum 11 and 10. Their maxProd is 110 (11*10)

    Example 2:
    Input: root = [1,null,2,3,4,null,null,5,6]
    Output: 90
    Explanation: Remove the red edge and get 2 binary trees with totalSum 15 and 6.Their maxProd is 90 (15*6)

    Example 3:
    Input: root = [2,3,9,10,7,8,6,5,4,11,1]
    Output: 1025

    Example 4:
    Input: root = [1,1]
    Output: 1
    
    Constraints:
    The number of nodes in the tree is in the range [2, 5 * 104].
    1 <= Node.val <= 104

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
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

class Solution {
    long long totalSum = 0;
    long long maxProd = 0;

   public:
    int maxProduct(TreeNode *root) {
        // traverse the tree and find out total totalSum for the tree
        totalSum = dfs(root);
        // at each node, update max product
        dfs(root);
        return maxProd % int(10e9 + 7);
    }

    int dfs(TreeNode *root) {
        if (!root) return 0;

        // find the subtree sum
        int curr = dfs(root->left) + dfs(root->right) + root->val;
        // totalSum-subTreeSum is how you detach this subtree
        maxProd = max(maxProd, (totalSum - curr) * curr);
        return curr;
    }
};
