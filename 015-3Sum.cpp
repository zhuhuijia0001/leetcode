
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    
        vector<vector<int>> vecRes;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            
            int sum = 0 - first;
            
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                if (nums[low] + nums[high] < sum) {
                    low++;
                } else if (nums[low] + nums[high] > sum) {
                    high--;
                } else {
                    vector<int> vec;
                    int second = nums[low];
                    int third = nums[high];
                    
                    vec.push_back(first);
                    vec.push_back(second);
                    vec.push_back(third);
                    
                    vecRes.push_back(vec);
                    
                    low++;
                    high--;
                    while (low < high && nums[low] == second) {
                        low++;
                    }
                    
                    while (high > low && nums[high] == third) {
                        high--;
                    }
                }
            }
            
            while (i < nums.size() - 2 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        
        return vecRes;
    }
};