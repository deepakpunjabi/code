/*
  
  Sort a linked list in O(n log n) time using constant space complexity.

  Example 1:
  Input: 4->2->1->3
  Output: 1->2->3->4

  Example 2:
  Input: -1->5->3->4->0
  Output: -1->0->3->4->5
  
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MergeSortLL {
   public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *tail;

        while (fast && fast->next) {
            tail = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = tail->next;
        tail->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);

        return merge(left, right);
    }

    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode *res = new ListNode();
        ListNode *node = res;

        while (left && right) {
            if (left->val < right->val) {
                res->next = left;
                left = left->next;
            } else {
                res->next = right;
                right = right->next;
            }
            res = res->next;
        }

        if (left) res->next = left;
        if (right) res->next = right;

        return node->next;
    }
};
