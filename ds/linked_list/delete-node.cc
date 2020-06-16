/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9]

Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
 

Note:

The linked list will have at least two elements.
All of the nodes' values will be unique.
The given node will not be the tail and it will always be a valid node of the linked list.
Do not return anything from your function.
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class DeleteNodeNaive {
   public:
    void deleteNode(ListNode* node) {
        while (node->next->next) {
            node->val = node->next->val;
            node = node->next;
        }
        ListNode* tmp = node->next;
        node->val = node->next->val;
        node->next = nullptr;
        delete tmp;
    }
};

/* 
Complexity Analysis
Time: We visit each node once, hence O(n)
Space: We don't store additional information, hence O(1)
*/

class DeleteNode {
   public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

/* 
Complexity Analysis
Time: O(1)
Space: O(1)
*/
