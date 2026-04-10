#include <stdlib.h>
#define MOD 1000000007

int maxSumMinProduct(int* nums, int numsSize) {
    long long *prefix = (long long*)malloc(sizeof(long long) * (numsSize + 1));
    prefix[0] = 0;

    for(int i = 0; i < numsSize; i++) {
        prefix[i+1] = prefix[i] + nums[i];
    }

    int *stack = (int*)malloc(sizeof(int) * numsSize);
    int top = -1;

    long long maxProduct = 0;

    for(int i = 0; i <= numsSize; i++) {
        while(top != -1 && (i == numsSize || nums[stack[top]] > nums[i])) {
            int idx = stack[top--];

            int left = (top == -1) ? 0 : stack[top] + 1;
            int right = i - 1;

            long long sum = prefix[right + 1] - prefix[left];
            long long product = sum * nums[idx];

            if(product > maxProduct) {
                maxProduct = product;
            }
        }
        stack[++top] = i;
    }

    free(prefix);
    free(stack);

    return maxProduct % MOD;
}
