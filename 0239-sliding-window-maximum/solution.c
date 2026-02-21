/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int* deque = (int*)malloc(numsSize * sizeof(int)); // store indices
    int front = 0, back = -1;

    *returnSize = numsSize - k + 1;

    for (int i = 0; i < numsSize; i++) {

        // 1️⃣ Remove indices outside window
        if (front <= back && deque[front] <= i - k)
            front++;

        // 2️⃣ Remove smaller elements
        while (front <= back && nums[deque[back]] < nums[i])
            back--;

        // 3️⃣ Add current index
        deque[++back] = i;

        // 4️⃣ Window formed → record max
        if (i >= k - 1)
            result[i - k + 1] = nums[deque[front]];
    }

    free(deque);
    return result;
}
