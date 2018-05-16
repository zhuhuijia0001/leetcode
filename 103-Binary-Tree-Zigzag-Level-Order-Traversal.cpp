
//solution 1
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > vec_group;
        
      	if (root == nullptr) {
			return vec_group;
		}

		queue<TreeNode *> q; 
		q.push(root);

        bool leftToRight = true;
        
		while(!q.empty()) { 
			int n = q.size();
            vector<int> vec;
            for (int i = 0; i < n; i++) {
                TreeNode * t=q.front(); 
				q.pop(); 
				vec.push_back(t->val);
				
				if (t->left) {
					q.push(t->left); 
				} 
				if (t->right) {
					q.push(t->right); 
				} 
            }
		
            if (!leftToRight) {
                int i = 0, j = vec.size() - 1;
                while (i < j) {
                    int t = vec[i];
                    vec[i] = vec[j];
                    vec[j] = t;
                    
                    i++;
                    j--;
                }
            }
			vec_group.push_back(vec);
            
            leftToRight = !leftToRight;
		}
        
        return vec_group;
    }
};

//solution 2
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > vec_group;
        
      	if (root == nullptr) {
			return vec_group;
		}

		queue<TreeNode *> q; 
		q.push(root);

        bool leftToRight = true;
        
		while(!q.empty()) { 
			int n = q.size();
            vector<int> vec(n);
            for (int i = 0; i < n; i++) {
                TreeNode * t=q.front(); 
				q.pop();
                
                int index = leftToRight ? i : n - 1 - i;
				vec[index] = t->val;
				
				if (t->left) {
					q.push(t->left); 
				} 
				if (t->right) {
					q.push(t->right); 
				} 
            }
			vec_group.push_back(vec);
            
            leftToRight = !leftToRight;
		}
        
        return vec_group;
    }
};