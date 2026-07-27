#include <stdbool.h>
bool isAnagram(char* s, char* t) {
    int l1 =strlen(s);
    int l2 = strlen(t);
    int count[26] = {0};
if(l1 != l2)
{
    return false;
}
for (int i = 0; i < l1; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    
    return true;
}
