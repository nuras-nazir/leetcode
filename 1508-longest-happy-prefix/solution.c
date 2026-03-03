#include <string.h>
#include <stdlib.h>

char* longestPrefix(char* s) {
    int n = strlen(s);
    if (n == 0) return "";

    int* lps = (int*)malloc(sizeof(int) * n);
    lps[0] = 0;

    int len = 0;
    int i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    int longest = lps[n - 1];
    free(lps);

    if (longest == 0) return "";

    s[longest] = '\0';
    return s;
}
