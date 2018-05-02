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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
private:
    TreeNode *helper(vector<int> &postorder, int post_start, int post_end, 
                     vector<int> &inorder, int in_start, int in_end) {
        
        if (post_start > post_end || in_start > in_end) {
            return nullptr;
        }
        
        int val = postorder[post_end];
        
        int i;
        for (i = in_start; i <= in_end; i++) {
            if (val == inorder[i]) {
                break;
            }
        }
        
        TreeNode *node = new TreeNode(val);
        int len = i - in_start;
        node->left = helper(postorder, post_start, post_start + len - 1, inorder, in_start, i - 1);
        
        node->right = helper(postorder, post_start + len, post_end - 1, inorder, i + 1, in_end);
        
        return node;
    }
};
