#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    char* prefix = strs[0];  // assume first string is prefix

    for (int i = 1; i < strsSize; i++) {
        int j = 0;

        // compare prefix with current string
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }

        prefix[j] = '\0';  // cut prefix here

        if (prefix[0] == '\0')
            return "";  // no common prefix
    }

    return prefix;
}
