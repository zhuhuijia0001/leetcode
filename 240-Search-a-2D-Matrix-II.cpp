class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int col = matrix[0].size() - 1;
        int row = 0;
        
        while (col >= 0 && row < matrix.size())
        {
            if (matrix[row][col] > target)
            {
                col--;
            }
            else if (matrix[row][col] < target)
            {
                row++;
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
};