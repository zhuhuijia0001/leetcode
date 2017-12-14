//Solution 1
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> vec_len;
        
        for (int i = 0; i < nums.size(); i++) {
            int j;
            for (j = 0; j < vec_len.size(); j++) {
                if (nums[i] <= vec_len[j]) {
                    break;
                }
            }
            
            if (j < vec_len.size()) {
                vec_len[j] = nums[i];
            } else {
                vec_len.push_back(nums[i]);
            }
        }
        
        return vec_len.size();
    }
};

//Solution 2
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {

		vector<int> vec_len;

		for (int i = 0; i < nums.size(); i++) {

			auto itr = lower_bound(vec_len.begin(), vec_len.end(), nums[i]);

			if (itr != vec_len.end()) {
				*itr = nums[i];
			} else {
				vec_len.push_back(nums[i]);
			}
		}

		return vec_len.size();
	}
};
