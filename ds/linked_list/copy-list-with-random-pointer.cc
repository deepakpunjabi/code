/*

    A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
    Return a deep copy of the list.

    The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
    
    Example 1:
    Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

    Example 2:
    Input: head = [[1,1],[2,1]]
    Output: [[1,1],[2,1]]

    Example 3:
    Input: head = [[3,null],[3,0],[3,null]]
    Output: [[3,null],[3,0],[3,null]]

    Example 4:
    Input: head = []
    Output: []
    Explanation: Given linked list is empty (null pointer), so return null.
    
    Constraints:
    -10000 <= Node.val <= 10000
    Node.random is null or pointing to a node in the linked list.
    Number of Nodes will not exceed 1000.

*/

#include <string>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

// works for graphs as well
class CopyLL {
    /* 
        Explanation:
        First pass: Copy LL using next pointer. Keep mapping of original nodes to new nodes.
        Second pass: Update random pointers using the map of original -> copy

        TC: O(n)
        SC: O(n) for map
    */
   public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> mapping;
        Node* original = head;
        Node* copy = copyListAndUpdateMap(original, mapping);

        mapRandomPointers(head, copy, mapping);
        return copy;
    }

    Node* copyListAndUpdateMap(Node* head, unordered_map<Node*, Node*>& mapping) {
        Node* copy = new Node(0);
        Node* res = copy;

        while (head) {
            Node* tmp = new Node(head->val);
            mapping[head] = tmp;

            copy->next = tmp;
            copy = copy->next;
            head = head->next;
        }

        return res->next;
    }

    void mapRandomPointers(Node* original, Node* copy, unordered_map<Node*, Node*>& mapping) {
        Node* o = original;
        Node* c = copy;

        while (o) {
            if (o->random) {
                Node* m = mapping[o->random];
                c->random = m;
            }

            o = o->next;
            c = c->next;
        }
    }
};
