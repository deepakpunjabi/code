/* 

    Given head which is a reference node to a singly-linked list. 
    The value of each node in the linked list is either 0 or 1. 
    The linked list holds the binary representation of a number.
    Return the decimal value of the number in the linked list.

    Example 1:
    Input: head = [1,0,1]
    Output: 5
    Explanation: (101) in base 2 = (5) in base 10

    Example 2:
    Input: head = [0]
    Output: 0

    Example 3:
    Input: head = [1]
    Output: 1

    Example 4:
    Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
    Output: 18880

    Example 5:
    Input: head = [0,0]
    Output: 0

    Constraints:
    - The Linked List is not empty.
    - Number of nodes will not exceed 30.
    - Each node's value is either 0 or 1.

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Simple {
   public:
    int getDecimalValue(ListNode *head) {
        ListNode *tmp = head;
        int mul = 1;

        while (tmp->next) {
            mul *= 2;

            tmp = tmp->next;
        }

        int res = 0;
        tmp = head;
        while (tmp) {
            res += tmp->val * mul;
            mul /= 2;

            tmp = tmp->next;
        }

        return res;
    }
};

class Bitwise {
   public:
    int getDecimalValue(ListNode *head) {
        int res = head->val;
        while (head->next) {
            // multiply result by 2 and add LSB
            res = (res << 1) | head->next->val;
            head = head->next;
        }

        return res;
    }
};
