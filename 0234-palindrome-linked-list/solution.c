/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdbool.h>

// reverse helper
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while(curr != NULL) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {

    if(head == NULL || head->next == NULL)
        return true;

    // find middle
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half
    struct ListNode* second = reverse(slow);

    struct ListNode* first = head;

    // compare
    while(second != NULL) {
        if(first->val != second->val)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}
