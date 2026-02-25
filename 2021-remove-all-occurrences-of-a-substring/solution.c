#include <string.h>
#include <stdlib.h>

char* removeOccurrences(char* s, char* part) {
    int n = strlen(s);
    int m = strlen(part);

    char* result = (char*)malloc((n + 1) * sizeof(char));
    int top = 0;  // acts like stack pointer

    for (int i = 0; i < n; i++) {
        result[top++] = s[i];
        result[top] = '\0';

        // Check if last m chars match "part"
        if (top >= m && strncmp(result + top - m, part, m) == 0) {
            top -= m;  // remove substring
        }
    }

    result[top] = '\0';
    return result;
}
