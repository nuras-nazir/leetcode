/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void connectNodes(struct Node* root) {
    if (root == NULL || root->left == NULL)
        return;

    // connect left child to right child
    root->left->next = root->right;

    // connect right child to next subtree
    if (root->next != NULL)
        root->right->next = root->next->left;

    connectNodes(root->left);
    connectNodes(root->right);
}

struct Node* connect(struct Node* root) {
    connectNodes(root);
    return root;
}
