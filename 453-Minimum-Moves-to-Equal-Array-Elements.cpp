class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int min = nums[0];
        int sum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            
            if (min > nums[i]) {
                min = nums[i];
            }
        }
        
        return sum - min * nums.size();
    }
};