// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    
    long left = 1;
    long right = n;

    while (left < right) {
        
        long mid = left + (right - left) / 2;

        if (isBadVersion(mid)) {
            right = mid;        // first bad is mid or before
        } else {
            left = mid + 1;     // first bad is after mid
        }
    }

    return left;
}
