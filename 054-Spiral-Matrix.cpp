class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> vec;
       
		if (matrix.empty()) {
			return vec;
		}

		matrix.reserve(matrix.size() * matrix[0].size());

        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        
        while (true) {
            int i;
            for (i = left; i <= right; i++) {
                vec.push_back(matrix[top][i]);
            }
          
            if (++top > bottom) {
                break;
            }
            
            for (i = top; i <= bottom; i++) {
                vec.push_back(matrix[i][right]);
            }
        
            if (left > --right) {
                break;
            }
            
            for (i = right; i >= left; i--) {
                vec.push_back(matrix[bottom][i]);
            }
            
            if (top > --bottom) {
                break;
            }
            
            for (i = bottom; i >= top; i--) {
                vec.push_back(matrix[i][left]);
            }
            
            if (++left > right) {
                break;
            }
        }
        
        return vec;
    }
};