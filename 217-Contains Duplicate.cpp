class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        vector<int>::iterator itr;
        
        set<int> myset;
        
        pair<set<int>::iterator, bool> ret;
        
        for (itr = nums.begin(); itr != nums.end(); ++itr)
        {
            ret = myset.insert(*itr);
            if (!ret.second)
            {
                return true;
            }
        }
        
        return false;
    }
};