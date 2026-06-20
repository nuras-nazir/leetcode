int absVal(int x)
{
    return x < 0 ? -x : x;
}

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int minimumDifference(int* nums, int numsSize)
{
    int n = numsSize / 2;

    int left[15], right[15];

    for(int i = 0; i < n; i++)
    {
        left[i] = nums[i];
        right[i] = nums[i + n];
    }

    int total = 0;
    for(int i = 0; i < numsSize; i++)
        total += nums[i];

    int maxMask = 1 << n;

    int *L[16], *R[16];
    int lsz[16] = {0}, rsz[16] = {0};

    for(int i = 0; i <= n; i++)
    {
        L[i] = malloc(maxMask * sizeof(int));
        R[i] = malloc(maxMask * sizeof(int));
    }

    for(int mask = 0; mask < maxMask; mask++)
    {
        int cnt = 0;
        int sumL = 0, sumR = 0;

        for(int j = 0; j < n; j++)
        {
            if(mask & (1 << j))
            {
                cnt++;
                sumL += left[j];
                sumR += right[j];
            }
        }

        L[cnt][lsz[cnt]++] = sumL;
        R[cnt][rsz[cnt]++] = sumR;
    }

    for(int i = 0; i <= n; i++)
        qsort(R[i], rsz[i], sizeof(int), cmp);

    int ans = 2147483647;

    for(int k = 0; k <= n; k++)
    {
        for(int i = 0; i < lsz[k]; i++)
        {
            int sum1 = L[k][i];

            int target = total / 2 - sum1;

            int *arr = R[n - k];
            int sz = rsz[n - k];

            int lo = 0, hi = sz - 1;

            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;

                int chosen = sum1 + arr[mid];

                int diff = absVal(total - 2 * chosen);

                if(diff < ans)
                    ans = diff;

                if(arr[mid] < target)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }

            if(lo < sz)
            {
                int chosen = sum1 + arr[lo];
                int diff = absVal(total - 2 * chosen);

                if(diff < ans)
                    ans = diff;
            }

            if(hi >= 0)
            {
                int chosen = sum1 + arr[hi];
                int diff = absVal(total - 2 * chosen);

                if(diff < ans)
                    ans = diff;
            }
        }
    }

    for(int i = 0; i <= n; i++)
    {
        free(L[i]);
        free(R[i]);
    }

    return ans;
}
