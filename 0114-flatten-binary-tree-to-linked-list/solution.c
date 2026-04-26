/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* prev = NULL;

void flattenTree(struct TreeNode* root) {
    if (root == NULL) return;

    // Step 1: go right first
    flattenTree(root->right);

    // Step 2: go left
    flattenTree(root->left);

    // Step 3: rewire
    root->right = prev;
    root->left = NULL;

    prev = root;
}

void flatten(struct TreeNode* root) {
    prev = NULL;
    flattenTree(root);
}
