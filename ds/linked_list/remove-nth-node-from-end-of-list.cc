/* 

Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/* 

    Use two pointers, keep d distance between the.
    There are 3 sub-cases for this problem:
    - remove head
    - remove tail
    - remove node from in-between

 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* node = head;
    ListNode* remove = head;

    // don't make node null
    // eg. remove([1], 1)
    while (n-- && node->next) {
        node = node->next;
    }

    while (node->next) {
        node = node->next;
        remove = remove->next;
    }

    // verify due to which condition you broke, accordingly remove node
    if (remove == head && n == 0) return head->next;

    remove->next = remove->next->next;
    return head;
}

// simplify logic a bit by introducing a dummy node
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* res = new ListNode(0);
    res->next = head;

    ListNode* slow = res;
    ListNode* fast = res;

    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return res->next;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* res = new ListNode(0);
    res->next = head;

    ListNode* slow = res; // keep slow a bit extra slow! this handles removal of head
    ListNode* fast = head;

    while (n--) {
        fast = fast->next;
    }

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return res->next;
}
