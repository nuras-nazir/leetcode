int solve(int* nums, int n, int index, int sum, int target)
{
    if(index == n)
        return (sum == target);

    return solve(nums, n, index + 1, sum + nums[index], target) +
           solve(nums, n, index + 1, sum - nums[index], target);
}

int findTargetSumWays(int* nums, int numsSize, int target)
{
    return solve(nums, numsSize, 0, 0, target);
}
