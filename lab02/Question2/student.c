// Question2/Student.c
// ------------------------------------------------------------
// CS Lab - Design Circular Queue (RING BUFFER / QUEUE PRACTICE)
//
// Task:
// Implement the circular queue functions declared in Student.h.
//
// You are designing a fixed-size queue with capacity k.
// The queue supports enqueue/dequeue in O(1) time using a circular array.
//
// Recommended invariants (simple + robust):
// - Use an integer `size` to track how many elements are currently stored.
// - Queue is empty  <=> size == 0
// - Queue is full   <=> size == capacity
// - `head` points to the current front element
// - `tail` points to the next insertion position
// - Wrap indices using modulo: (idx + 1) % capacity
//
// Examples (k = 3):
//   enQueue(1) -> true    queue: [1]
//   enQueue(2) -> true    queue: [1,2]
//   enQueue(3) -> true    queue: [1,2,3]
//   enQueue(4) -> false   (full)
//   Rear()     -> 3
//   isFull()   -> true
//   deQueue()  -> true    queue: [2,3]
//   enQueue(4) -> true    queue: [2,3,4]
//   Rear()     -> 4
//   Front()    -> 2
//
// Return values rules:
// - Front / Rear should return -1 if the queue is empty.
//
// How to run tests (from the folder containing the Makefile):
//   make run2
// ------------------------------------------------------------

#include "Student.h"
#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue)); // allocate struct
    if (!obj) return NULL;

    obj->data = (int*)malloc(sizeof(int) * k); // allocate array
    if (!obj->data) {
        free(obj);
        return NULL;
    }

    obj->capacity = k;
    obj->head = 0;
    obj->tail = 0;
    obj->size = 0; // initially empty
    
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (!obj || obj->size == obj->capacity) return false; // full check

    obj->data[obj->tail] = value; // insert at tail
    obj->tail = (obj->tail + 1) % obj->capacity; // wrap around
    obj->size++; // increase count
    
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (!obj || obj->size == 0) return false; // empty check

    obj->head = (obj->head + 1) % obj->capacity; // move head
    obj->size--; // decrease count
    
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (!obj || obj->size == 0) return -1; // empty check
    return obj->data[obj->head]; // return front
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (!obj || obj->size == 0) return -1; // empty check
    int lastIdx = (obj->tail + obj->capacity - 1) % obj->capacity; // last element index
    return obj->data[lastIdx];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return !obj || obj->size == 0; // true if empty
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj && obj->size == obj->capacity; // true if full
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj) {
        free(obj->data); // free array
        free(obj);       // free struct
    }
}