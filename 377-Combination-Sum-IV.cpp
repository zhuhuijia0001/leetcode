class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target + 1);
        
        sort(nums.begin(), nums.end());
        
        dp[0] = 1;
        
        for (int i = 1; i <= target; i++) {
            for (int a : nums) {
                if (a > i) {
                    break;
                }
                
                dp[i] += dp[i - a];
            }
        }
        
        return dp.back();
    }
};