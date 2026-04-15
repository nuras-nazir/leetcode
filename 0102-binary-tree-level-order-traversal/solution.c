int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int maxSize = 10000;

    int** result = malloc(maxSize * sizeof(int*));
    *returnColumnSizes = malloc(maxSize * sizeof(int));

    struct TreeNode** queue = malloc(maxSize * sizeof(struct TreeNode*));

    int front = 0, rear = 0;
    queue[rear++] = root;

    int level = 0;

    while (front < rear) {
        int size = rear - front;

        result[level] = malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            result[level][i] = node->val;

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }

        level++;
    }

    *returnSize = level;
    return result;
}
