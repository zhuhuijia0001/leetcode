class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() < 2) {
			return nums.size();
		}

		int i;
		for (i = 1; i < nums.size(); i++) {
			if (nums[i] - nums[i - 1] != 0) {
				break;
			}
		}

		if (i == nums.size()) {
			return 1;
		}

		int len = 2;

		int diff = nums[i] - nums[i - 1];
		for (i++ ; i < nums.size(); i++) {
			if (diff * (nums[i] - nums[i - 1]) < 0) {
				len++;

				diff = nums[i] - nums[i - 1];
			}
		}

		return len;
	}
};