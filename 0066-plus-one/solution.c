/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    // Traverse from last digit
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;  // carry
    }

    // If all digits were 9 (e.g., 999 → 1000)
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;
    }

    *returnSize = digitsSize + 1;
    return result;
}

