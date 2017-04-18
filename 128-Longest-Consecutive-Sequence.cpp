class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        int i;
        
        int prev = 0;
        
        int max = 1;
        
        for (i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == 1)
            {
                if (i - prev + 1 > max)
                {
                    max = i - prev + 1;
                }
            }
            else if (nums[i] == nums[i - 1])
            {
                prev++;
            }
            else
            {
                prev = i;
            }
        }
        
        return max;
    }
};