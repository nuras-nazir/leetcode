/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *result = (int *)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int k = 0;

    for (int i = 0; i < nums1Size; i++) {
        int found = 0;

        // Check if nums1[i] is already in result
        for (int x = 0; x < k; x++) {
            if (result[x] == nums1[i]) {
                found = 1;
                break;
            }
        }

        if (found)
            continue;

        // Check if nums1[i] exists in nums2
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                result[k++] = nums1[i];
                break;
            }
        }
    }

    *returnSize = k;
    return result;
}
