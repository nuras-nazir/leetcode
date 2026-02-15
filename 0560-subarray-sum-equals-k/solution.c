#include <stdlib.h>

#define TABLE_SIZE 40001   // enough for constraints

typedef struct {
    int key;
    int value;
} HashEntry;

HashEntry table[TABLE_SIZE];

int hash(int key) {
    int h = key % TABLE_SIZE;
    if (h < 0) h += TABLE_SIZE;
    return h;
}

void insert(int key, int value) {
    int idx = hash(key);
    while (table[idx].value != 0 && table[idx].key != key) {
        idx = (idx + 1) % TABLE_SIZE;
    }
    table[idx].key = key;
    table[idx].value += value;
}

int get(int key) {
    int idx = hash(key);
    while (table[idx].value != 0) {
        if (table[idx].key == key)
            return table[idx].value;
        idx = (idx + 1) % TABLE_SIZE;
    }
    return 0;
}


int subarraySum(int* nums, int numsSize, int k) {
    // reset table
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].value = 0;
    }

    int count = 0;
    int sum = 0;

    insert(0, 1);  // base case

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];

        count += get(sum - k);

        insert(sum, 1);
    }

    return count;
}
