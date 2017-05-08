class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        else if (nums.size() == 1)
        {
            return nums[0];
        }
        else if (nums.size() == 2)
        {
            return nums[0] >= nums[1] ? nums[0] : nums[1];
        }
        
        vector<int> vec(nums.size());
        vec[0] = nums[0];
        vec[1] = nums[0] >= nums[1] ? nums[0] : nums[1];
        for (int i = 2; i < nums.size(); i++)
        {
            vec[i] = vec[i - 2] + nums[i] >= vec[i - 1] ? vec[i - 2] + nums[i] : vec[i - 1];
        }
        
        return vec.back();
    }
};