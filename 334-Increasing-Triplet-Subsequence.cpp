class Solution 
{
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int max1 = INT_MAX, max2 = INT_MAX;
        
        for (auto a : nums)
        {
            if (a <= max1)
            {
                max1 = a;
            }
            else if (a <= max2)
            {
                max2 = a;
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
};