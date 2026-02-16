void moveZeroes(int* nums, int numsSize) {
    int pos = 0;  // position to place next non-zero

    // Step 1: move non-zero elements forward
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[pos++] = nums[i];
        }
    }

    // Step 2: fill remaining with zeros
    while (pos < numsSize) {
        nums[pos++] = 0;
    }
}

