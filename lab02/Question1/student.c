// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------
#include "Student.h"
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

bool isValid(const char *s) {
    // Corner cases
    if (s == NULL) return false;
    
    size_t len = strlen(s);
    if (len == 0) return true;
    if (len % 2 != 0) return false; // Odd length can't be balanced

    // Use a char array as a stack. 
    // Max size needed is the length of the string.
    char stack[len];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char current = s[i];

        // 1. If it's an opening bracket, push it
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } 
        // 2. If it's a closing bracket
        else {
            // Stack cannot be empty if we are looking for a match
            if (top == -1) return false;

            char lastOpen = stack[top--]; // Pop the top

            // Check for mismatch
            if (current == ')' && lastOpen != '(') return false;
            if (current == '}' && lastOpen != '{') return false;
            if (current == ']' && lastOpen != '[') return false;
        }
    }

    // 3. If top is -1, all brackets were matched and popped
    return top == -1;
}