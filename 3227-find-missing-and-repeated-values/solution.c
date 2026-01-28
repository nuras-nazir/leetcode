/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int n = gridSize;
    int total = n * n;

    int freq[2501] = {0};

    // Count frequencies
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            freq[grid[i][j]]++;
        }
    }

    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // Find repeated and missing
    for (int i = 1; i <= total; i++) {
        if (freq[i] == 2)
            ans[0] = i;   // repeated
        else if (freq[i] == 0)
            ans[1] = i;   // missing
    }

    return ans;
}

