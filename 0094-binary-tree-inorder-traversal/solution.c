int* result;
int capacity;

void inorder(struct TreeNode* root, int* returnSize) {
    if (!root) return;

    inorder(root->left, returnSize);

    if (*returnSize >= capacity) {
        capacity *= 2;
        result = realloc(result, sizeof(int) * capacity);
    }

    result[(*returnSize)++] = root->val;

    inorder(root->right, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    capacity = 100;
    result = malloc(sizeof(int) * capacity);
    *returnSize = 0;

    inorder(root, returnSize);

    return result;
}
