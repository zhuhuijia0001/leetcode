class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        
        for (int i = 0; i < (row + 1) / 2; i++)
        {
            for (int j = 0; j < col / 2; j++)
            {
                int tmp = matrix[i][j];
                
                matrix[i][j] = matrix[col - 1 - j][i];
                matrix[col - 1 - j][i] = matrix[col - 1 - i][col - 1 - j];
                matrix[col - 1 - i][col - 1 - j] = matrix[j][col - 1 - i];
                matrix[j][col - 1 - i] = tmp;
            }
        }
    }
};