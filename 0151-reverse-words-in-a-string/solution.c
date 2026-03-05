#include <string.h>
#include <stdlib.h>

char* reverseWords(char* s) {
    int n = strlen(s);
    char* result = (char*)malloc(n + 1);
    
    int i = n - 1;
    int pos = 0;

    while(i >= 0) {

        while(i >= 0 && s[i] == ' ')
            i--;

        if(i < 0) break;

        int j = i;

        while(j >= 0 && s[j] != ' ')
            j--;

        for(int k = j + 1; k <= i; k++)
            result[pos++] = s[k];

        result[pos++] = ' ';

        i = j;
    }

    if(pos > 0) pos--;

    result[pos] = '\0';

    return result;
}
