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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> vec;
        
        if (root != NULL)
        {
            postorder(root, vec);
        }
        
        return vec;
    }
    
private:
    void postorder(TreeNode *node, vector<int> &vec)
    {
        if (node->left != NULL)
        {
            postorder(node->left, vec);
        }
        
        if (node->right != NULL)
        {
            postorder(node->right, vec);
        }
        
        vec.push_back(node->val);
    }
};