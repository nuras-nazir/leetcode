/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {

    if(head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: find length and last node
    struct ListNode* temp = head;
    int n = 1;

    while(temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Step 2: make circular
    temp->next = head;

    // Step 3: reduce k
    k = k % n;

    // Step 4: find new tail
    int steps = n - k;

    struct ListNode* newTail = head;
    for(int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 5: break
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
