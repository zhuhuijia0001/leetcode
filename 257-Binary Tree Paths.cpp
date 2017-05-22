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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> vec;
        
        string str;
        
        if (root != NULL)
        {
            str = int2String(root->val);
            
            travelTreePaths(root, vec, str);
        }
        
        return vec;
    }
    
private:
    
    string int2String(int val)
    {
        string str;
        
        bool negative = false;
        
        if (val == 0)
        {
            str += '0';
        }
        
        if (val < 0)
        {
            negative = true;
            
            val = -val;
        }
        
        while (val > 0)
        {
            int r = val % 10;
            
            str.insert(str.begin(), '0' + r);
            
            val /= 10;
        }
        
        if (negative)
        {
            str = '-' + str;
        }
        
        return str;
    }
    
    void travelTreePaths(TreeNode *node, vector<string> &vec, string str)
    {
        if (node->left == NULL && node->right == NULL)
        {
            vec.push_back(str);
            
            return;
        }
        
        if (node->left != NULL)
        {
            travelTreePaths(node->left, vec, str + "->" + int2String(node->left->val));
        }
        
        if (node->right != NULL)
        {
            travelTreePaths(node->right, vec, str + "->" + int2String(node->right->val));
        }
    }
};