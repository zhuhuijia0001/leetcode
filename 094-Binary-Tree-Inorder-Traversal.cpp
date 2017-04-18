/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> vec;
        
        if (root != NULL)
        {
            inorder(root, vec);
        }
        
        return vec;
    }
    
private:
    void inorder(TreeNode *node, vector<int>& vec)
    {
        if (node->left != NULL)
        {
            inorder(node->left, vec);
        }
        
        vec.push_back(node->val);
        
        if (node->right != NULL)
        {
            inorder(node->right, vec);
        }
    }
};