class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> vec;
        
        if (n == 0) {
            return vec;
        }
        
        for (int i = 0; i < n; i++) {
            vec.push_back(vector<int>(n));
        }
        
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        
        int k = 1;
        
        while (true) {
            
            int i;
            
            for (int i = left; i <= right; i++) {
                vec[top][i] = k++;
            }
            
            if (++top > bottom) {
                break;
            }
            
            for (int i = top; i <= bottom; i++) {
                vec[i][right] = k++;
            }
            
            if (left > --right) {
                break;
            }
            
            for (int i = right; i >= left; i--) {
                vec[bottom][i] = k++;
            }
            
            if (top > --bottom) {
                break;
            }
            
            for (int i = bottom; i >= top; i--) {
                vec[i][left] = k++;
            }
            
            if (++left > right) {
                break;
            }
        }
        
        return vec;
    }
};