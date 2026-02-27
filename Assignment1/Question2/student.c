#include "Student.h"

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2

//code begins ------------------------------------------------------------------

int majorityElement(int* nums, int numsSize) {

    int Var = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            Var = nums[i];  // Pick new
        }

        if (nums[i] == Var) {
            count++;  // Same = increase count
        } else {
            count--;  // Different = decrease count
        }
    }

    return Var;
}


//code ends--------------------------------------------------------------------