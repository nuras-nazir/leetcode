bool wordBreak(char* s, char** wordDict, int wordDictSize) {

    int n = strlen(s);

    bool dp[n + 1];

    for(int i = 0; i <= n; i++)
        dp[i] = false;

    dp[0] = true;

    for(int i = 1; i <= n; i++) {

        for(int j = 0; j < wordDictSize; j++) {

            int len = strlen(wordDict[j]);

            if(i >= len && dp[i - len]) {

                if(strncmp(s + i - len, wordDict[j], len) == 0) {

                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[n];
}
