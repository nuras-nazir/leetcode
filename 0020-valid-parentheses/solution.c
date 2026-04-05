#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int n = strlen(s);
    char* stack = (char*)malloc(n);
    int top = -1;

    for(int i = 0; i < n; i++) {
        char c = s[i];

        // opening brackets
        if(c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } 
        else {
            // stack empty → invalid
            if(top == -1) {
                free(stack);
                return false;
            }

            char topChar = stack[top--];

            if((c == ')' && topChar != '(') ||
               (c == '}' && topChar != '{') ||
               (c == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool valid = (top == -1);
    free(stack);
    return valid;
}
