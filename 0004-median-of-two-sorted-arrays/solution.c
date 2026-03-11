#include <limits.h>

double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {

    if(m > n)
        return findMedianSortedArrays(nums2,n,nums1,m);

    int low = 0, high = m;

    while(low <= high){

        int i = (low + high) / 2;
        int j = (m + n + 1) / 2 - i;

        int maxLeft1 = (i==0) ? INT_MIN : nums1[i-1];
        int minRight1 = (i==m) ? INT_MAX : nums1[i];

        int maxLeft2 = (j==0) ? INT_MIN : nums2[j-1];
        int minRight2 = (j==n) ? INT_MAX : nums2[j];

        if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1){

            if((m+n)%2==0){
                int left = maxLeft1 > maxLeft2 ? maxLeft1 : maxLeft2;
                int right = minRight1 < minRight2 ? minRight1 : minRight2;
                return (left + right) / 2.0;
            }
            else{
                return maxLeft1 > maxLeft2 ? maxLeft1 : maxLeft2;
            }
        }

        else if(maxLeft1 > minRight2)
            high = i - 1;

        else
            low = i + 1;
    }

    return 0.0;
}
