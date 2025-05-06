/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool mirror(struct TreeNode* node1, struct TreeNode* node2) {
    if (node1 == NULL && node2 == NULL) //if both sides are nothing then it mirrors
        return true;
    if (node1 == NULL || node2 == NULL) //if one side has something and the other doesn't then it doesn't mirror (won't fire for both because previous if)
        return false;
    //recurses and will return false if any node doesn't mirror
    return (node1->val == node2->val) && mirror(node1->left, node2->right) && mirror(node1->right, node2->left);
}
bool isSymmetric(struct TreeNode* root) {
    if (root==NULL) 
        return true;
    //begin recursion
    return mirror(root->left, root->right);
}
