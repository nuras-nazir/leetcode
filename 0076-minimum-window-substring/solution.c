#include <stdio.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    if (!s || !t) return "";

    int need[128] = {0};

    // Build frequency table for t
    for (int i = 0; t[i]; i++)
        need[t[i]]++;

    int left = 0, right = 0;
    int required = strlen(t);

    int minLen = INT_MAX;
    int start = 0;

    while (s[right]) {
        // include current char
        if (need[s[right]] > 0)
            required--;

        need[s[right]]--;
        right++;

        // when valid window found
        while (required == 0) {
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
            }

            // shrink window
            need[s[left]]++;
            if (need[s[left]] > 0)
                required++;

            left++;
        }
    }

    if (minLen == INT_MAX) return "";

    // terminate substring
    s[start + minLen] = '\0';
    return s + start;
}
