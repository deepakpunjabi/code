// Reverse a singly linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*

    This problem contains 2 cases:
    - empty list: []
    - non-empty list: 
        - [1](odd-length, single element), 
        - [1,2](even-length), 
        - [1,2,3] (this last one is just for extra measure)

    TC: O(n), processing each element once
    SC: O(1)

*/
ListNode *reverseList(ListNode *head) {
    if (!head or !head->next) return head; // covers [] and [1]

    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr) {
        ListNode *nextptr = curr->next;
        curr->next = prev; // main logic

        prev = curr;
        curr = nextptr;
    }

    return prev;
}
