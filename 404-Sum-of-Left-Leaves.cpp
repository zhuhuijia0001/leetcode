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
    int sumOfLeftLeaves(TreeNode* root) {
        
        int val = 0;
        if (root != nullptr) {
            
            if (root->left != nullptr) {
                bool bLeft = true;
                impl(root->left, &bLeft, &val);
            }
        
            if (root->right != nullptr) {
                bool bLeft = false;
                impl(root->right, &bLeft, &val);
            }
        }
        
        return val;
    }
    
private:
    void impl(TreeNode *node, bool *bLeft, int *curVal) {
        if (node->left == nullptr && node->right == nullptr && *bLeft) {
            *curVal += node->val;
        }
        
        if (node->left != nullptr) {
            bool bLeft = true;
            impl(node->left, &bLeft, curVal);
        }
        
        if (node->right != nullptr) {
            bool bLeft = false;
            impl(node->right, &bLeft, curVal);
        }
    }
};