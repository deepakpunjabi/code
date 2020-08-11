/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> mapping;
        Node *original = head;
        Node* copy = copyListAndUpdateMap(original, mapping);
        
        mapRandomPointers(head, copy, mapping);
        return copy;
    }
    
    Node* copyListAndUpdateMap(Node* head, unordered_map<Node*, Node*> &mapping) {
        Node* copy = new Node(0);
        Node* res = copy;
        
        while (head) {
            Node *tmp = new Node(head->val);
            mapping[head] = tmp;
            
            copy->next = tmp;
            copy = copy->next;
            head = head->next;
        }
        
        return res->next;
    }
    
    void mapRandomPointers(Node* original, Node* copy, unordered_map<Node*, Node*> &mapping) {
        Node *o = original;
        Node *c = copy;
        
        while (o) {
            if (o->random) {
                Node *m = mapping[o->random];
                c->random = m;    
            } 
            
            o = o->next;
            c = c->next;
        }
        
    }
};
