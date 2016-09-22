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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> vec;
        
        if (root != NULL)
        {
            preorder(root, vec);
        }
        
        return vec;
    }
    
private:
    void preorder(TreeNode *node, vector<int> &vec)
    {
        vec.push_back(node->val);
        
        if (node->left != NULL)
        {
            preorder(node->left, vec);
        }
        
        if (node->right != NULL)
        {
            preorder(node->right, vec);
        }
    }
};