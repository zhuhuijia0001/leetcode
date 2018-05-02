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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
private:
    TreeNode *helper(vector<int> &preorder, int pre_start, int pre_end, 
                     vector<int> &inorder, int in_start, int in_end) {
        
        if (pre_start > pre_end || in_start > in_end) {
            return nullptr;
        }
        
        int val = preorder[pre_start];
        
        int i;
        for (i = in_start; i <= in_end; i++) {
            if (val == inorder[i]) {
                break;
            }
        }
        
        TreeNode *node = new TreeNode(val);
        int len = i - in_start;
        node->left = helper(preorder, pre_start + 1, pre_start + len, inorder, in_start, i - 1);
        
        node->right = helper(preorder, pre_start + len + 1, pre_end, inorder, i + 1, in_end);
        
        return node;
    }
};
