/* 
    Remove all elements from a linked list of integers that have value val.

    Example:
    Input:  1->2->6->3->4->5->6, val = 6
    Output: 1->2->3->4->5
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* res = new ListNode();
    ListNode* tmp = res;

    while (head) {
        if (head->val != val) {
            tmp->next = head;
            tmp = tmp->next;
        }

        head = head->next;
    }
    // for cases, such as [1,2] val=2,
    // res list's last node 1 will still have pointer to 2
    tmp->next = nullptr; 
    
    return res->next;
}

/*
[1,2,3]
3

res = [0]
tmp = [0]

while:
head=1
    0-nxt = 1
    tmp = 1

head=2
    1-nxt=2
    tmp=2
    
head=3

2-nxt=null

----

[]
3

----

[1,2]
3

----

[1,2]
1

*/
