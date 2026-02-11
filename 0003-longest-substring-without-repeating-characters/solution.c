#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];
    
    // initialize all to -1
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int maxLen = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        
        // if character already seen and inside window
        if (lastIndex[s[right]] >= left) {
            left = lastIndex[s[right]] + 1;
        }

        lastIndex[s[right]] = right;

        int currLen = right - left + 1;
        if (currLen > maxLen) {
            maxLen = currLen;
        }
    }

    return maxLen;
}

