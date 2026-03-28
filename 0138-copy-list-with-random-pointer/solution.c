struct Node* copyRandomList(struct Node* head) {

    if (!head) return NULL;

    struct Node* curr = head;

    // Step 1: interleave copied nodes
    while (curr) {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = curr->val;

        copy->next = curr->next;
        curr->next = copy;

        curr = copy->next;
    }

    // Step 2: assign random pointers
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        else
            curr->next->random = NULL;

        curr = curr->next->next;
    }

    // Step 3: separate the lists (IMPORTANT FIX HERE)
    curr = head;
    struct Node* newHead = head->next;

    while (curr) {
        struct Node* copy = curr->next;

        curr->next = copy->next;  // restore original

        if (copy->next)
            copy->next = copy->next->next;  // FIXED

        curr = curr->next;
    }

    return newHead;
}
