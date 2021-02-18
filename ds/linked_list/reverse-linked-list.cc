// Reverse a singly linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr) {
        ListNode *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

// similar approach
ListNode *reverseList(ListNode *head) {
    if (!head) return nullptr;

    ListNode *prev = nullptr;
    ListNode *curr = head;
    
    while (curr->next) {
        ListNode *tmp = curr->next;
        curr->next = prev;

        prev = curr;
        curr = tmp;
    }
    curr->next = prev;

    return curr;
}
