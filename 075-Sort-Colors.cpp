class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        partition(partition(nums.begin(), nums.end(), bind2nd(equal_to<int>(), 0)), 
                    nums.end(), bind2nd(equal_to<int>(), 1));
    }
};