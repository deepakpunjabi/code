#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) return nullptr;
    return insert(nums, 0, nums.size() - 1);
}

TreeNode* insert(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;

    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = insert(nums, left, mid - 1);
    root->right = insert(nums, mid + 1, right);

    return root;
}