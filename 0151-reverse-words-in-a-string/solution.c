#include <stdlib.h>
#include <string.h>

void reverse(char* s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

char* reverseWords(char* s) {
    int n = strlen(s);
    char* result = (char*)malloc(n + 1);

    int i = 0, j = 0;

    // 1️⃣ Remove extra spaces
    while (i < n) {
        while (i < n && s[i] == ' ') i++;   // skip spaces

        if (i >= n) break;

        if (j > 0) result[j++] = ' ';       // add single space

        while (i < n && s[i] != ' ')
            result[j++] = s[i++];
    }
    result[j] = '\0';

    // 2️⃣ Reverse whole string
    reverse(result, 0, j - 1);

    // 3️⃣ Reverse each word
    int start = 0;
    for (int k = 0; k <= j; k++) {
        if (result[k] == ' ' || result[k] == '\0') {
            reverse(result, start, k - 1);
            start = k + 1;
        }
    }

    return result;
}
