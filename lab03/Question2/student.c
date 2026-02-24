// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      if (head == NULL || head->next == NULL)
            return head;      //no swap

            struct ListNode* newHead = head->next;    //new head
            struct ListNode* prev = NULL; //last tail
            struct ListNode* curr = head; //first in pair

      while (curr != NULL && curr->next != NULL) {

            struct ListNode* nextPair = curr->next->next;
            struct ListNode* second = curr->next;

            second->next = curr;    //swap
            curr->next = nextPair;  //connect next

      if (prev != NULL)
            prev->next = second;    //connect last

            prev = curr;      //move prev forward
            curr = nextPair;  //move curr to nextPair
      }

      return newHead;
}