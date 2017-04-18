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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int> > vec_group;
        
        vector<int> vec;
        
      	if (root == NULL)
		{
			return vec_group;
		}

		queue<TreeNode *> q; 
		q.push(root);

		int num = 1; 
		while(!q.empty()) 
		{ 
			int next=0; 
			
			vec.clear();
			
			while (num--) 
			{ 
				TreeNode * t=q.front(); 
				q.pop(); 
				vec.push_back(t->val);
				
				if (t->left) 
				{ 
					next++; 
					q.push(t->left); 
				} 
				if (t->right) 
				{ 
					next++; 
					q.push(t->right); 
				} 
			}
			num = next; 
			
			vec_group.insert(vec_group.begin(), vec);
		}
		
		return vec_group;
    }
};