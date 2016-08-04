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
    int kthSmallest(TreeNode* root, int k) 
    {
        int count = 0;
        
        stack<TreeNode *> stk;
        
        while (!stk.empty() || root != NULL)
        {
            if (root != NULL)
            {
                stk.push(root);
                
                root = root->left;
            }
            else
            {
                root = stk.top();
                stk.pop();
                
                count++;
                if (count == k)
                {
                    break;
                }
                
                root = root->right;
            }
        }
        
        return root->val;
    }
};
