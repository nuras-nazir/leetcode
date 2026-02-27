#include <stdio.h>

int compress(char* chars, int charsSize) {
    int write = 0;   // position to write compressed data
    int read = 0;    // position to read

    while (read < charsSize) {
        char current = chars[read];
        int count = 0;

        // count occurrences of current char
        while (read < charsSize && chars[read] == current) {
            read++;
            count++;
        }

        // write the character
        chars[write++] = current;

        // write count if > 1
        if (count > 1) {
            char buffer[10];
            int len = sprintf(buffer, "%d", count);

            for (int i = 0; i < len; i++) {
                chars[write++] = buffer[i];
            }
        }
    }

    return write;  // new length
}
