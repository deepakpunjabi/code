/* 

lid: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

You are given a doubly linked list which in addition to the next and previous pointers, 
it could have a child pointer, which may or may not point to a separate doubly linked list. 
These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, 
as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

Example 1:
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]

Example 2:
Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:
The input multilevel linked list is as follows:
  1---2---NULL
  |
  3---NULL

Example 3:
Input: head = []
Output: []

How multilevel linked list is represented in test case:
We use the multilevel linked list from Example 1 above:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
The serialization of each level is as follows:

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
To serialize all levels together we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
Merging the serialization of each level and removing trailing nulls we obtain:

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 

Constraints:
Number of Nodes will not exceed 1000.
1 <= Node.val <= 10^5

*/

#include <iostream>
#include <stack>

using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

/* 

This problem can be done both iteratively and with recursion(without stack).
Below implementation is easy to understand one.

*/

Node* flatten(Node* head) {
    if (!head) return head;

    // initialize object with some dummy value
    Node* res = new Node{0, nullptr, nullptr, nullptr};
    Node* node = res;

    stack<Node*> st;
    st.push(head);

    while (!st.empty()) {
        Node* tmp = st.top();
        st.pop();

        // add current node in result
        node->next = tmp;
        tmp->prev = node;

        // push next and than child on top of it for proper priority
        if (tmp->next) st.push(tmp->next);
        if (tmp->child) st.push(tmp->child);

        // just cleanup of child pointer as leetcode verifies it
        node->child = nullptr;
        node = node->next;
    }

    // prev is still pointing to dummy node, leetcode verification for doubly ll
    res = res->next;
    res->prev = nullptr;

    return res;
}

// helper method to print out ll
void print(Node* res) {
    Node* t = res->next;
    while (t) {
        if (t->prev) {
            cout << t->prev->val << "-";
        }
        cout << t->val << "-";
        if (t->next) {
            cout << t->next->val << "-";
        }
        if (t->child) {
            cout << t->child->val << "-";
        }
        cout << endl;
        t = t->next;
    }
}
