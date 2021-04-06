/*

    Given an integer array nums where the elements are sorted in ascending order, 
    convert it to a height-balanced binary search tree.
    A height-balanced binary tree is a binary tree in which 
    the depth of the two subtrees of every node never differs by more than one.

    nums is sorted in a strictly increasing order.

*/

#include <treenode.h>

#include <vector>
using namespace std;

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return convert(nums, 0, nums.size() - 1);
}

TreeNode* convert(vector<int>& nums, int low, int high) {
    if (low > high) return nullptr;

    int mid = low + (high - low) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = convert(nums, low, mid - 1);
    root->right = convert(nums, mid + 1, high);

    return root;
}

/* 

TC: O(n), size of the input array, we are always appending treenode at leaf and not searching for insert position
SC: O(1), no extra allocation apart from the output

*/
