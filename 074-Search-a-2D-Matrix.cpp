class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int low, high;
        
        int mid;
        
        low = 0; 
        high = matrix.size() - 1;
        
        while (low <= high)
        {
            mid = (high - low) / 2 + low;
            
            if (matrix[mid][0] < target)
            {
                low = mid + 1;
            }
            else if (matrix[mid][0] > target)
            {
                high = mid - 1;
            }
            else 
            {
                return true;
            }
        }
        
        if (high < 0)
        {
            return false;
        }
        
        int index = high;
        
        low = 0;
        high = matrix[high].size() - 1;
        while (low <= high)
        {
            mid = (high - low) / 2 + low;
            
            if (matrix[index][mid] < target)
            {
                low = mid + 1;
            }
            else if (matrix[index][mid] > target)
            {
                high = mid - 1;
            }
            else 
            {
                return true;
            }
        }
        
        return false;
    }
};