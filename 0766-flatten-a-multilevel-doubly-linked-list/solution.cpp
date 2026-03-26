/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr != NULL) {

            if (curr->child != NULL) {

                // find tail of child
                Node* child = curr->child;
                Node* tail = child;

                while (tail->next != NULL) {
                    tail = tail->next;
                }

                // connect tail with next
                tail->next = curr->next;
                if (curr->next != NULL) {
                    curr->next->prev = tail;
                }

                // connect curr with child
                curr->next = child;
                child->prev = curr;

                // remove child
                curr->child = NULL;
            }

            curr = curr->next;
        }

        return head;
    }
};
