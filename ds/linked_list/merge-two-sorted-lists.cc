/*

Merge two sorted linked lists and return it as a new sorted list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MergeList {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        // important step,
        // if you forget this your result will have only last node
        ListNode* merged = res;

        while (l1 && l2) {
            if (l1->val <= l2->val) { // '<' is also fine
                res->next = l1;
                l1 = l1->next;
            } else {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        if (l1) res->next = l1;
        if (l2) res->next = l2;

        return merged->next;
    }
};

/*

    Important Test Cases;
    [][]
    [][1]
    [1,2][1,2]
    [1,2,3][1,2]
    [5][1,2] // non-overlapping lists

    TC: O(m+n)
    SC: O(1)

*/
