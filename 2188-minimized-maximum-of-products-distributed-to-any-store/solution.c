int minimizedMaximum(int n, int* quantities, int quantitiesSize) {

    int low = 1;
    int high = 0;

    for(int i = 0; i < quantitiesSize; i++)
        if(quantities[i] > high)
            high = quantities[i];

    int ans = high;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        long stores = 0;

        for(int i = 0; i < quantitiesSize; i++)
            stores += (quantities[i] + mid - 1) / mid;   // ceil

        if(stores <= n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
