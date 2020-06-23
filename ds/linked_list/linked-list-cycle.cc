
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool hasCycle(ListNode* head) {
    if (!head) return false;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        if (slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}

/*
test cases:
[]
[1,2]
[1,2]->[1,2]
*/
