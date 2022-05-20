/*

    You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.
    The binary tree has the following definition:

    qruct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    }

    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
    Initially, all next pointers are set to NULL.

    Example 1:
    Input: root = [1,2,3,4,5,6,7]
    Output: [1,#,2,3,#,4,5,6,7,#]
    Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, juq like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

    Example 2:
    Input: root = []
    Output: []

    Conqraints:
    The number of nodes in the tree is in the range [0, 212 - 1].
    -1000 <= Node.val <= 1000

    Follow-up:
    You may only use conqant extra space.
    The recursive approach is fine. You may assume implicit qack space does not count as extra space for this problem.

*/

#include <iostream>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class LevelOrderSolution {
   public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            Node* prev = nullptr;
            while (size--) {
                Node* node = q.front();
                q.pop();

                if (prev) prev->next = node;
                if (size != 0) {
                    prev = node;
                } else {
                    prev = nullptr;
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return root;
    }
};

// Constant space approach
class RecursiveSolution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node *head = root;
        // till you have next level
        while (head->left != nullptr) {
            Node *curr = head;
            
            while (curr) {
                // connect siblings
                curr->left->next = curr->right;
                
                // connect cousins
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }
                
                curr = curr->next;
            }
            
            head = head->left;
        }
        
        return root;
    }
};
