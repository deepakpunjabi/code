/*
    Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
    To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. 
    If pos is -1, then there is no cycle in the linked list.
    Note: Do not modify the linked list.

    Example 1:
    Input: head = [3,2,0,-4], pos = 1
    Output: tail connects to node index 1
    Explanation: There is a cycle in the linked list, where tail connects to the second node.

    Example 2:
    Input: head = [1,2], pos = 0
    Output: tail connects to node index 0
    Explanation: There is a cycle in the linked list, where tail connects to the first node.

    Example 3:
    Input: head = [1], pos = -1
    Output: no cycle
    Explanation: There is no cycle in the linked list.

    Follow-up:
    Can you solve it without using extra space?
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class GetStartNodeOfLLCycle {
   public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *start = hasCycle(head);
        if (!start) return nullptr;

        // eventually they will meet!
        // mathematical proof is required to show that they will meet at start
        while (start != head) {
            start = start->next;
            head = head->next;
        }

        return start;
    }

    // Floyd's Cycle detection algorithm
    // Tortoise Hare pointers
    ListNode *hasCycle(ListNode *head) {
        if (!head) return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return slow;
        }

        return nullptr;
    }
};
