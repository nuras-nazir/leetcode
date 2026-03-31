/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getKth(struct ListNode* curr, int k) {
    while(curr != NULL && k > 0) {
        curr = curr->next;
        k--;
    }
    return curr;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* groupPrev = &dummy;

    while(1) {

        struct ListNode* kth = getKth(groupPrev, k);
        if(kth == NULL) break;

        struct ListNode* groupNext = kth->next;

        // reverse group
        struct ListNode* prev = groupNext;
        struct ListNode* curr = groupPrev->next;

        while(curr != groupNext) {
            struct ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // reconnect
        struct ListNode* temp = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = temp;
    }

    return dummy.next;
}
