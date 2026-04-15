int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(10000 * sizeof(int));
    struct TreeNode* stack[10000];

    int top = -1, index = 0;
    struct TreeNode* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        result[index++] = curr->val;

        curr = curr->right;
    }

    *returnSize = index;
    return result;
}
