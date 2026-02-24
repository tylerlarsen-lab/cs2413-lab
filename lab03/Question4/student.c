// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "Student.h"

int middleNodeValue(struct ListNode *head) {

    struct ListNode* slow = head;   //1 step
    struct ListNode* fast = head;   //2 steps

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;  //sslow
        fast = fast->next->next; //fast
    }

    return slow->val;
}