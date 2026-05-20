typedef struct Trie {

    struct Trie* child[26];
    bool end;

} Trie;

Trie* trieCreate() {

    Trie* node = (Trie*)malloc(sizeof(Trie));

    for(int i = 0; i < 26; i++)
        node->child[i] = NULL;

    node->end = false;

    return node;
}

void trieInsert(Trie* obj, char* word) {

    Trie* cur = obj;

    for(int i = 0; word[i]; i++) {

        int idx = word[i] - 'a';

        if(cur->child[idx] == NULL)
            cur->child[idx] = trieCreate();

        cur = cur->child[idx];
    }

    cur->end = true;
}

bool trieSearch(Trie* obj, char* word) {

    Trie* cur = obj;

    for(int i = 0; word[i]; i++) {

        int idx = word[i] - 'a';

        if(cur->child[idx] == NULL)
            return false;

        cur = cur->child[idx];
    }

    return cur->end;
}

bool trieStartsWith(Trie* obj, char* prefix) {

    Trie* cur = obj;

    for(int i = 0; prefix[i]; i++) {

        int idx = prefix[i] - 'a';

        if(cur->child[idx] == NULL)
            return false;

        cur = cur->child[idx];
    }

    return true;
}

void trieFree(Trie* obj) {

    for(int i = 0; i < 26; i++) {

        if(obj->child[i] != NULL)
            trieFree(obj->child[i]);
    }

    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
