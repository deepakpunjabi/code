struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (!head->next) return head;
    ListNode *h1 = head, *h2 = head->next, *h22 = head->next;

    bool i = true;
    while (h1->next && h2->next) {
        if (i) {
            h1->next = h1->next->next;
            h1 = h1->next;
        } else {
            h2->next = h2->next->next;
            h2 = h2->next;
        }
        i = !i;
    }

    h1->next = h22;

    return head;
}