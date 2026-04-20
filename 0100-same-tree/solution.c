/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // both null → same
    if (p == NULL && q == NULL) return true;

    // one null → not same
    if (p == NULL || q == NULL) return false;

    // value mismatch
    if (p->val != q->val) return false;

    // check left and right
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}
