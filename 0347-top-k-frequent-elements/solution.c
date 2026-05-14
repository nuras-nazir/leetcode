/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    int freq[20001] = {0};

    for(int i = 0; i < numsSize; i++) {
        freq[nums[i] + 10000]++;
    }

    int* ans = (int*)malloc(sizeof(int) * k);

    int idx = 0;

    while(idx < k) {

        int maxFreq = 0;
        int num = 0;

        for(int i = 0; i < 20001; i++) {

            if(freq[i] > maxFreq) {

                maxFreq = freq[i];
                num = i - 10000;
            }
        }

        ans[idx++] = num;

        freq[num + 10000] = 0;
    }

    *returnSize = k;

    return ans;
}
