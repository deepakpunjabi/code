struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    // cout << t1 << " " << t2 << endl;
    if (!t1 && !t2) return nullptr;
    if (t1 && !t2) return t1;
    if (!t1 && t2) return t2;

    TreeNode* left = mergeTrees(t1->left, t2->left);
    TreeNode* right = mergeTrees(t1->right, t2->right);

    // TreeNode *tmp = new TreeNode(t1->val + t2->val, left, right);
    return new TreeNode(t1->val + t2->val, left, right);
}

// merge second tree into first tree
TreeNode* mergeTrees1(TreeNode* t1, TreeNode* t2) {
    // Recursive, merge into t1
    if (!t1) return t2;
    if (!t2) return t1;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}
