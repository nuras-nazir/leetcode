int lengthOfLIS(int* nums, int numsSize)
{
    int dp[2500];
    int maxLen = 1;

    for(int i = 0; i < numsSize; i++)
        dp[i] = 1;

    for(int i = 1; i < numsSize; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(nums[i] > nums[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }

        if(dp[i] > maxLen)
            maxLen = dp[i];
    }

    return maxLen;
}
