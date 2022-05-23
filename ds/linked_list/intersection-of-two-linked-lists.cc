/*

    Write a program to find the node at which the intersection of two singly linked lists begins.

    Example 1:
    Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
    Output: Reference of the node with value = 8
    Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). 
    From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. 
    There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

    Example 2:
    Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
    Output: Reference of the node with value = 2
    Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). 
    From the head of A, it reads as [0,9,1,2,4]. 
    From the head of B, it reads as [3,2,4]. 
    There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

    Example 3:
    Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
    Output: null
    Input Explanation: From the head of A, it reads as [2,6,4]. 
    From the head of B, it reads as [1,5]. 
    Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
    Explanation: The two lists do not intersect, so return null.

    Notes:
    - If the two linked lists have no intersection at all, return null.
    - The linked lists must retain their original structure after the function returns.
    - You may assume there are no cycles anywhere in the entire linked structure.
    - Your code should preferably run in O(n) time and use only O(1) memory.

*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        if (lenB > lenA) {
            swap(headA, headB);
        }

        int diff = abs(lenA - lenB);
        while (diff--) headA = headA->next;

        while (headA) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }

    int getLen(ListNode *head) {
        int length = 0;

        ListNode *curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        return length;
    }
};

class IterativeSolution {
   public:
    // find size of both LL and advance the bigger one with difference of size.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1 = size(headA);
        int size2 = size(headB);

        ListNode *first, *second;
        int diff;
        if (size1 >= size2) {
            first = headA;
            second = headB;
            diff = size1 - size2;
        } else {
            first = headB;
            second = headA;
            diff = size2 - size1;
        }

        while (diff--) {
            first = first->next;
        }

        while (first && second) {
            if (first == second) return first;
            first = first->next;
            second = second->next;
        }

        return nullptr;
    }

    int size(ListNode *node) {
        int n = 0;
        while (node) {
            ++n;
            node = node->next;
        }
        return n;
    }
};
