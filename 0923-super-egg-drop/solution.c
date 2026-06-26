int superEggDrop(int k, int n) {
    long long *dp = (long long *)calloc(k + 1, sizeof(long long));
    int moves = 0;

    while (dp[k] < n) {
        moves++;
        for (int e = k; e >= 1; e--) {
            dp[e] = dp[e] + dp[e - 1] + 1;
        }
    }

    free(dp);
    return moves;
}
