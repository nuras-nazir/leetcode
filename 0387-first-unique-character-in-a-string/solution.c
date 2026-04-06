#include <string.h>

int firstUniqChar(char* s) {
    int freq[26] = {0};

    // Step 1: count frequency
    for(int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: find first unique
    for(int i = 0; s[i] != '\0'; i++) {
        if(freq[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}
