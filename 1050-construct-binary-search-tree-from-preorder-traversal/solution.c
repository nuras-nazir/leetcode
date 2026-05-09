/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* build(int* preorder, int* index, int bound, int size) {

    if (*index >= size || preorder[*index] > bound)
        return NULL;

    struct TreeNode* root =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->val = preorder[*index];
    (*index)++;

    root->left = build(preorder, index, root->val, size);

    root->right = build(preorder, index, bound, size);

    return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {

    int index = 0;

    return build(preorder, &index, INT_MAX, preorderSize);
}
