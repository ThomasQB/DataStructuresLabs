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
 int total(struct TreeNode* node) { //pretty sure this is in the textbook
    if (node == NULL) {
        return 0;
    }
    return 1 + total(node->left) + total(node->right); //Return this node plus left and right subtree
}

void pre(struct TreeNode* node, int* res, int* i) {
    if (node == NULL) {
        return;
    }
    pre(node->left, res, i);
    res[*i] = node->val; // Add node value to array
    (*i)++;  //incriment index of array
    pre(node->right, res, i); //still in the textbook
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
        if (root == NULL) {
        *returnSize = 0;
        return NULL; //Edge case for no root
    }
    printf("%d",*returnSize);
    *returnSize = total(root); //Equal to the amount of nodes we have to return
    printf("\n%d",*returnSize); //returnsize = amnt of nulls in tree
    int* res = (int*)malloc(*returnSize * sizeof(int)); //make array
    int i = 0; //Index
    pre(root, res, &i); //Call the arraymaker
    return res;
}
