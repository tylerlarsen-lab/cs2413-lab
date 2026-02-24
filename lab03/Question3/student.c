// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {

    if (head == NULL || head->next == NULL)
        return false;   //no cycles 

    struct ListNode* slow = head;   //1 step
    struct ListNode* fast = head;   //2steps

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;  //slow
        fast = fast->next->next;    //fast

        if (slow == fast)   //there is a cycle
            return true;
    }

    return false;
}