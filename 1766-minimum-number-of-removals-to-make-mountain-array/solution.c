int minimumMountainRemovals(int* nums, int numsSize) {
    int *lis = (int *)malloc(numsSize * sizeof(int));
    int *lds = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && lis[j] + 1 > lis[i])
                lis[i] = lis[j] + 1;
        }
    }

    for (int i = numsSize - 1; i >= 0; i--) {
        lds[i] = 1;
        for (int j = numsSize - 1; j > i; j--) {
            if (nums[j] < nums[i] && lds[j] + 1 > lds[i])
                lds[i] = lds[j] + 1;
        }
    }

    int maxMountain = 0;

    for (int i = 1; i < numsSize - 1; i++) {
        if (lis[i] > 1 && lds[i] > 1) {
            int mountainLen = lis[i] + lds[i] - 1;
            if (mountainLen > maxMountain)
                maxMountain = mountainLen;
        }
    }

    free(lis);
    free(lds);

    return numsSize - maxMountain;
}
