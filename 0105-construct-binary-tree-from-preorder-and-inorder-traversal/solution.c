#include <stdlib.h>

int preorderIndex = 0;

// Helper to find index in inorder
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

struct TreeNode* build(int* preorder, int* inorder, int start, int end) {
    if (start > end) return NULL;

    // Step 1: pick root from preorder
    int rootVal = preorder[preorderIndex++];
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    // Step 2: find root in inorder
    int mid = findIndex(inorder, start, end, rootVal);

    // Step 3: build left and right
    root->left = build(preorder, inorder, start, mid - 1);
    root->right = build(preorder, inorder, mid + 1, end);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    preorderIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1);
}
