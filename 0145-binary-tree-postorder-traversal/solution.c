/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int* result = malloc(10000 * sizeof(int));
    struct TreeNode* stack[10000];

    int top = -1, index = 0;

    stack[++top] = root;

    while (top != -1) {
        struct TreeNode* node = stack[top--];

        result[index++] = node->val;

        if (node->left)
            stack[++top] = node->left;

        if (node->right)
            stack[++top] = node->right;
    }

    // reverse result
    for (int i = 0; i < index / 2; i++) {
        int temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }

    *returnSize = index;
    return result;
}
