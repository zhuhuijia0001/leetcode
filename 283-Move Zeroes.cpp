//Solution 1
class Solution {
public:
    static bool isNoneZero(int a)
    {
    	if (a != 0)
    	{
    		return true;
    	}
    
    	return false;
    }
    
    void moveZeroes(vector<int>& nums) 
    {
	    stable_partition(nums.begin(), nums.end(), isNoneZero);
    }
};

//Solution 2
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
	    stable_partition(nums.begin(), nums.end(), std::bind(std::not_equal_to<int>(), std::placeholders::_1, 0));
    }
};
