//Solution 1
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i = 0;
        
        int curLen;
        int maxLen = 0;
        
        while (i < nums.size()) {
            while (i < nums.size() && nums[i] == 0) {
                i++;
            }
            
            curLen = 0;
            while (i < nums.size() && nums[i] == 1) {
                curLen++;
                if (curLen > maxLen) {
                    maxLen = curLen;
                }
                
                i++;
            }
        }
        
        return maxLen;
    }
};

//Solutiion 2
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int curLen = 0;
        int maxLen = 0;
        
        for (auto n : nums) {
            if (n == 1) {
                curLen++;
                
                maxLen = max(curLen, maxLen);
            } else {
                curLen = 0;
            }
        }
        
        return maxLen;
    }
};
