#include <ctype.h>   // for isalnum(), tolower()
#include <string.h>  // for strlen()

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {

        // skip non-alphanumeric from left
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // skip non-alphanumeric from right
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // compare lowercase characters
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

