int compare(const void *a, const void *b) {
    int *p1 = *(int **)a;
    int *p2 = *(int **)b;
    return p1[1] - p2[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize) {
    qsort(pairs, pairsSize, sizeof(int *), compare);

    int count = 0;
    int end = -1001;  

    for (int i = 0; i < pairsSize; i++) {
        if (pairs[i][0] > end) {
            count++;
            end = pairs[i][1];
        }
    }

    return count;
}
