#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    *returnSize = nums1Size;

    int* result = (int*)malloc(sizeof(int) * nums1Size);

    int* stack = (int*)malloc(sizeof(int) * nums2Size);
    int top = -1;

    int* map = (int*)malloc(sizeof(int) * 10001);
    for(int i = 0; i < 10001; i++) map[i] = -1;

    // process nums2
    for(int i = 0; i < nums2Size; i++) {

        while(top != -1 && nums2[i] > stack[top]) {
            map[stack[top]] = nums2[i];
            top--;
        }

        stack[++top] = nums2[i];
    }

    // fill result
    for(int i = 0; i < nums1Size; i++) {
        result[i] = map[nums1[i]];
    }

    free(stack);
    free(map);

    return result;
}
