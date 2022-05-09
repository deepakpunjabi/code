/*

    Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, 
    or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
    Design an algorithm to serialize and deserialize a binary tree. 
    There is no restriction on how your serialization/deserialization algorithm should work. 
    You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
    Clarification: The input/output format is the same as how LeetCode serializes a binary tree. 
    You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

    Example 1:
    Input: root = [1,2,3,null,null,4,5]
    Output: [1,2,3,null,null,4,5]

    Example 2:
    Input: root = []
    Output: []
    
    Constraints:
    The number of nodes in the tree is in the range [0, 104].
    -1000 <= Node.val <= 1000

 */

#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        return serialize(root, true);
    }

    string serialize(TreeNode *root, bool left) {
        if (!root) return "";

        string res = left ? "(" : "{";

        res += to_string(root->val);
        if (root->left) {
            res += serialize(root->left, true);
        }
        if (root->right) {
            res += serialize(root->right, false);
        }

        res += left ? ")" : "}";

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        stack<TreeNode *> st;

        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == ')' or data[i] == '}') {
                TreeNode *node = st.top();
                while (true) {
                    if (st.top()->val == '(' - '0' or (st.top()->val == '{' - '0' and st.top()->right == nullptr and st.top()->left == nullptr)) {
                        break;
                    } else {
                        st.pop();
                    }
                }
                st.pop();

                if (st.empty()) {
                    return node;
                }

                TreeNode *root = st.top();

                if (data[i] == ')') {
                    root->left = node;
                    root = root->left;
                } else {
                    root->right = node;
                    root = root->right;
                }
            } else {
                string num;
                TreeNode *curr;
                bool neg;
                if (isalnum(data[i])) {
                    neg = data[i - 1] == '-' ? true : false;
                }
                while (isalnum(data[i])) {
                    num += data[i];
                    ++i;
                }
                if (num == "") {
                    curr = new TreeNode(data[i] - '0');
                } else {
                    int n = stoi(num);
                    if (neg) {
                        n = -n;
                    }
                    curr = new TreeNode(n);
                    --i;
                }

                st.push(curr);
            }
        }

        return st.empty() ? nullptr : st.top();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
