/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* temp = &dummy;

    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry) {

        int sum = carry;

        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        carry = sum / 10;

        temp->next = newNode;
        temp = temp->next;
    }

    return dummy.next;
}
