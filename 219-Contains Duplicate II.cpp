class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int i;
        
        map<int, int> mymap;
        
        map<int, int>::iterator mapitr;
        
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr)
        {
            mapitr = mymap.find(*itr);
            if (mapitr != mymap.end())
            {
                //find 
                if (itr - nums.begin() - mapitr->second <= k)
                {
                    return true;
                }
                else
                {
                    mapitr->second = itr - nums.begin();
                }
            }
            else
            {
                mymap.insert(pair<int, int>(*itr, itr - nums.begin()));
            }
        }
        
        return false;
    }
};