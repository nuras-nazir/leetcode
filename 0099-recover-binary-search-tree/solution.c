/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *first = NULL;
struct TreeNode *second = NULL;
struct TreeNode *prev = NULL;

void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);

    // violation found
    if (prev != NULL && prev->val > root->val) {

        // first wrong node
        if (first == NULL)
            first = prev;

        // second wrong node
        second = root;
    }

    prev = root;

    inorder(root->right);
}

void recoverTree(struct TreeNode* root) {
    first = second = prev = NULL;

    inorder(root);

    // swap values
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
}
