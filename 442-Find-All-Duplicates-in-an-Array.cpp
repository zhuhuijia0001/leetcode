//Solution 1
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> vecCount(nums.size());
        vector<int> vecRes;
        
        for (auto n : nums) {
            vecCount[n - 1]++;
        }
        
        for (int i = 0; i < vecCount.size(); i++) {
            if (--vecCount[i] > 0) {
                vecRes.push_back(i + 1);
            }
        }
        
        return vecRes;
    }
};

//Solution 2
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> vecRes;
        
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }
        
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] - 1 != i) {
                vecRes.push_back(nums[i]);
            }
        }
        
        return vecRes;
    }
};
