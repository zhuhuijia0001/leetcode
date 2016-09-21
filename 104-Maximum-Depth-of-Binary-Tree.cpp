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
    int maxDepth(TreeNode* root) 
    {
        if (root == NULL)
        {
            return 0;
        }
        
        int left_max = maxDepth(root->left);
        int right_max = maxDepth(root->right);
        
        if (left_max >= right_max)
        {
            return left_max + 1;
        }
        
        return right_max + 1;
    }
};