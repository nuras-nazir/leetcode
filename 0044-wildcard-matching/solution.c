bool isMatch(char *s, char *p) {
    int m = strlen(s);
    int n = strlen(p);

    bool *dp = (bool *)calloc(n + 1, sizeof(bool));
    dp[0] = true;

    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*')
            dp[j] = dp[j - 1];
    }

    for (int i = 1; i <= m; i++) {
        bool prev = dp[0];
        dp[0] = false;

        for (int j = 1; j <= n; j++) {
            bool temp = dp[j];

            if (p[j - 1] == '*') {
                dp[j] = dp[j] || dp[j - 1];
            }
            else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                dp[j] = prev;
            }
            else {
                dp[j] = false;
            }

            prev = temp;
        }
    }

    bool ans = dp[n];
    free(dp);
    return ans;
}
