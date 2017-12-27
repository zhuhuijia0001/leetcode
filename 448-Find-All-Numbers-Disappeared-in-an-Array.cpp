//Solution 1
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int n : nums) {
            if (map.find(n) != map.end()) {
                map[n] = 2;
            } else {
                map[n] = 1;
            }
        }
        
        vector<int> vec;
        for (int i = 1; i <= nums.size(); i++) {
            if (map.find(i) == map.end()) {
                vec.push_back(i);
            }
        }
        
        return vec;
    }
};

//Solution 2
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                vec.push_back(i + 1);
            }
        }
        
        return vec;
    }
};

