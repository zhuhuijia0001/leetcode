/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    int checkHeight(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1)
        {
            return -1;
        }
        
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1)
        {
            return -1;
        }
        
        int diff = leftHeight - rightHeight;
        if (diff > 1 || diff < -1)
        {
            return -1;
        }
        else
        {
            return max(leftHeight, rightHeight) + 1;
        }
    }
    
    bool isBalanced(TreeNode* root) 
    {
        if (checkHeight(root) == -1)
        {
            return false;
        }
        
        return true;
    }
};