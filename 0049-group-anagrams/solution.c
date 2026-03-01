#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char*** result = malloc(strsSize * sizeof(char**));
    *returnColumnSizes = malloc(strsSize * sizeof(int));
    *returnSize = 0;

    int counts[strsSize][ALPHABET];
    memset(counts, 0, sizeof(counts));

    // build frequency map
    for (int i = 0; i < strsSize; i++) {
        for (int j = 0; strs[i][j]; j++) {
            counts[i][strs[i][j] - 'a']++;
        }
    }

    int groupRep[strsSize]; // store representative string index

    for (int i = 0; i < strsSize; i++) {
        int found = -1;

        for (int g = 0; g < *returnSize; g++) {
            int rep = groupRep[g];
            int same = 1;

            for (int c = 0; c < ALPHABET; c++) {
                if (counts[i][c] != counts[rep][c]) {
                    same = 0;
                    break;
                }
            }

            if (same) {
                found = g;
                break;
            }
        }

        if (found == -1) {
            result[*returnSize] = malloc(strsSize * sizeof(char*));
            (*returnColumnSizes)[*returnSize] = 0;
            groupRep[*returnSize] = i;
            found = (*returnSize)++;
        }

        result[found][(*returnColumnSizes)[found]++] = strs[i];
    }

    return result;
}
