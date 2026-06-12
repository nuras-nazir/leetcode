int coinChange(int* coins, int coinsSize, int amount)
{
    int dp[10001];

    for(int i = 0; i <= amount; i++)
        dp[i] = amount + 1;

    dp[0] = 0;

    for(int i = 1; i <= amount; i++)
    {
        for(int j = 0; j < coinsSize; j++)
        {
            if(coins[j] <= i)
            {
                if(dp[i - coins[j]] + 1 < dp[i])
                    dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }

    return (dp[amount] > amount) ? -1 : dp[amount];
}
