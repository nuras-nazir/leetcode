bool isSame(struct TreeNode* a, struct TreeNode* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;

    if (a->val != b->val) return false;

    return isSame(a->left, b->left) &&
           isSame(a->right, b->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL) return false;

    // check current node
    if (isSame(root, subRoot)) return true;

    // check left or right
    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}
