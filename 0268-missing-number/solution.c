int missingNumber(int* nums, int numsSize) {
    int sum = 0;

    // sum of array
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    // expected sum from 0 to n
    int expected = numsSize * (numsSize + 1) / 2;

    return expected - sum;
}

