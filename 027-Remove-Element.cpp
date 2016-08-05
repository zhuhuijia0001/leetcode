
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        nums.erase(remove_if(nums.begin(), nums.end(), bind2nd(equal_to<int>(), val)), nums.end());
        
        return nums.size();
    }
};