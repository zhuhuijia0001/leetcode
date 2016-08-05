class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!binary_search(nums.begin(), nums.end(), target)) {
            return vector<int>(2, -1);
        }
        
        auto pair = equal_range(nums.begin(), nums.end(), target);
        vector<int> vec = { distance(nums.begin(), pair.first), distance(nums.begin(), pair.second) - 1 };
        
        return vec;
    }
};