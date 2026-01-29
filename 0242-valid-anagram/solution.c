bool isAnagram(char* s, char* t) {
    int freq[26] = {0};
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z')
            c += 32;
        if (c >= 'a' && c <= 'z')
            freq[c - 'a']++;
    }

    for (i = 0; t[i] != '\0'; i++) {
        char c = t[i];
        if (c >= 'A' && c <= 'Z')
            c += 32;
        if (c >= 'a' && c <= 'z')
            freq[c - 'a']--;
    }

    for (i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return false;
    }

    return true;
}

