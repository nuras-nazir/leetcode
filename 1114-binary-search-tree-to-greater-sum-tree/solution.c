/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum = 0;

void traverse(struct TreeNode* root) {
    if (root == NULL) return;

    // Step 1: go right (greater values)
    traverse(root->right);

    // Step 2: update sum and node
    sum += root->val;
    root->val = sum;

    // Step 3: go left
    traverse(root->left);
}

struct TreeNode* bstToGst(struct TreeNode* root) {
    sum = 0;
    traverse(root);
    return root;
}
