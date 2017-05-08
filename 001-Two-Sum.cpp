
//Solution 1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mymap;
        unordered_map<int, int>::iterator mapitr;
        
        vector<int> vec_index;
        
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr)
        {
            mapitr = mymap.find(target - *itr);
            if (mapitr != mymap.end())
            {
                //found
                vec_index.push_back(mapitr->second);
                vec_index.push_back(itr - nums.begin());
                
                break;
            }
            else
            {
                mymap.insert(pair<int, int>(*itr, itr - nums.begin()));
            }
        }
        
        return vec_index;
    }
};

//Solution 2
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int sz = nums.size();
        int left = 0, right = sz - 1, sum = 0;

        vector<int> sorted (nums);
        std::sort(sorted.begin(), sorted.end());

        vector<int> index;
        while (left < right) 
        {
            sum = sorted[left] + sorted[right];
            if (sum == target) 
            {
                // find the answer
                for (int i = 0; i < sz; i++) 
                {
                    if (nums[i] == sorted[left])
                        index.push_back(i);
                    else if (nums[i] == sorted[right])
                        index.push_back(i);
                    if (index.size() == 2)
                        return index;
                }
            } 
            else if (sum > target) 
            {
                right--;
            } 
            else 
            {
                left++;
            }
        }
    }
};
