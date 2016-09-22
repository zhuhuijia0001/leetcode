class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        int i;
        
        vector<vector<int>> vec;
        
        vector<int> row;
        
        for (i = 0; i < numRows; i++)
        {
            int j;
            
            row.push_back(1);
            for (j = i - 1 ; j > 0; j--)
            {
                row[j] += row[j - 1];
            }
            
            vec.push_back(row);
        }
        
        return vec;
    }
};