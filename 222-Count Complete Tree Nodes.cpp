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
    int countNodes(TreeNode* root) {
        
        if (root == nullptr) {
            return 0;
        }
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        int leftCount = 1;
        int rightCount = 1;
        
        while (left != nullptr) {
            leftCount++;
            
            left = left->left;
        }
        
        while (right != nullptr) {
            rightCount++;
            
            right = right->right;
        }
        
        if (leftCount == rightCount) {
            return pow(2, leftCount) - 1;    
        }
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};