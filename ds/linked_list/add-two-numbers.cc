/* 

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *res = new ListNode();
    ListNode *node = res;

    int carry = 0;
    while (l1 && l2) {
        int sum = l1->val + l2->val + carry;
        if (sum > 9) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        ListNode *tmp = new ListNode(sum);
        res->next = tmp;

        l1 = l1->next;
        l2 = l2->next;
        res = res->next;
    }
    while (l1) {
        int sum = l1->val + carry;
        if (sum > 9) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        ListNode *tmp = new ListNode(sum);
        res->next = tmp;

        l1 = l1->next;
        res = res->next;
    }
    while (l2) {
        int sum = l2->val + carry;
        if (sum > 9) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        ListNode *tmp = new ListNode(sum);
        res->next = tmp;

        l2 = l2->next;
        res = res->next;
    }
    if (carry) {
        res->next = new ListNode(carry);
    }

    return node->next;
}

/*

test cases:
[][]
[][1]
[9][9]
[9][9,9]

*/

/*

time complexity: O(m+n), where m and n is size of two lists
space complexity: O(m+n), as we are creating new list

*/
