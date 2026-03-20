#define MOD 1000000007

int numberOfPermutations(int n, int** requirements, int requirementsSize, int* requirementsColSize) {
    // Build req array: req[end] = cnt (-1 if no requirement)
    int req[300];
    memset(req, -1, sizeof(req));
    for (int i = 0; i < requirementsSize; i++) {
        req[requirements[i][0]] = requirements[i][1];
    }
    
    // Find max inversions needed
    int maxInv = 0;
    for (int i = 0; i < requirementsSize; i++) {
        if (requirements[i][1] > maxInv) maxInv = requirements[i][1];
    }
    
    // dp[j] = number of permutations of [0..i] with j inversions
    long long* dp = calloc(maxInv + 1, sizeof(long long));
    dp[0] = 1;
    
    // If index 0 has a requirement, enforce it
    if (req[0] != -1) {
        if (req[0] != 0) {
            free(dp);
            return 0;
        }
    }
    
    for (int i = 1; i < n; i++) {
        long long* ndp = calloc(maxInv + 1, sizeof(long long));
        
        // Prefix sum of dp for sliding window
        long long* prefix = calloc(maxInv + 2, sizeof(long long));
        for (int j = 0; j <= maxInv; j++) {
            prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
        }
        
        // ndp[j] = sum of dp[j-k] for k=0..min(i,j)
        // = prefix[j+1] - prefix[max(0, j-i)]
        for (int j = 0; j <= maxInv; j++) {
            int lo = j - i > 0 ? j - i : 0;
            ndp[j] = (prefix[j + 1] - prefix[lo] + MOD) % MOD;
        }
        
        // If there's a requirement at index i, zero out all other counts
        if (req[i] != -1) {
            for (int j = 0; j <= maxInv; j++) {
                if (j != req[i]) ndp[j] = 0;
            }
        }
        
        free(dp);
        free(prefix);
        dp = ndp;
    }
    
    // Answer is dp[req[n-1]] (guaranteed end=n-1 exists)
    int ans = 0;
    for (int i = 0; i < requirementsSize; i++) {
        if (requirements[i][0] == n - 1) {
            ans = dp[requirements[i][1]];
            break;
        }
    }
    
    free(dp);
    return ans;
}
