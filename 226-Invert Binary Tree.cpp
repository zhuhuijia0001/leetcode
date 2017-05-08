/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) 
{
    struct TreeNode *p;
    
    if (root == NULL)
    {
        return NULL;
    }
    
    p = root->left;
    root->left = root->right;
    root->right = p;
    
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}