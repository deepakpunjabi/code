/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:
Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    void reorderList(ListNode *head) {
        if (!head) return;

        ListNode *mid = findMid(head);
        ListNode *second = mid->next;
        mid->next = nullptr; // really imp step, break first list from second

        ListNode *reversed = reverseList(second);

        head = mergeLists(head, reversed);
    }

    ListNode *findMid(ListNode *head) {
        if (!head) return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return prev;
    }

    ListNode *reverseList(ListNode *head) {
        if (!head) return nullptr;

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

    ListNode *mergeLists(ListNode *head1, ListNode *head2) {
        ListNode *node = new ListNode();
        ListNode *res = node;

        while (head1 && head2) {
            ListNode *nxt1 = head1->next; // imp2, head1 = head1->next won't work
            ListNode *nxt2 = head2->next; // this one is just for better readability

            node->next = head1;
            node->next->next = head2;
            node = node->next->next;

            head1 = nxt1;
            head2 = nxt2;
        }

        if (head1) node->next = head1;
        if (head2) node->next = head2;

        return res->next;
    }
};
