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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        
      	if (root == nullptr) {
			return vec;
		}

		queue<TreeNode *> q; 
		q.push(root);

		while(!q.empty()) { 
			int n = q.size();
            vec.push_back(q.back()->val);
            
            for (int i = 0; i < n; i++) {
                TreeNode * t=q.front(); 
				q.pop(); 
				
				if (t->left) {
					q.push(t->left); 
				} 
				if (t->right) {
					q.push(t->right); 
				} 
            }
		}
        
        return vec;        
    }
};