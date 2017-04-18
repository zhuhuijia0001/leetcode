
class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> vec;
        
        if (nums.empty())
        {
            return vec;
        }
        
        unordered_map<int, int> freq_map;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq_map.find(nums[i]) != freq_map.end())
            {
                freq_map[nums[i]]++;
            }
            else
            {
                freq_map[nums[i]] = 1;
            }
        }
        
        vector<pair<int, int>> vec_pair;
		vec_pair.reserve(k);
        
		auto itr = freq_map.begin();
        for (int i = 0; i < k; i++)
        {
            vec_pair.push_back(*itr);

			++itr;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompareGreater> pq(MyCompareGreater(), vec_pair);
        for ( ; itr != freq_map.end(); ++itr)
        {
            if ((*itr).second > pq.top().second)
            {
                pq.pop();
                
                pq.push(*itr);
            }
        }
        
        while (!pq.empty())
        {
            vec.push_back(pq.top().first);
            
            pq.pop();
        }
        
        return vec;
    }
    
private:
    struct MyCompareGreater
    {
    public:
        bool operator() (const pair<int, int> &op1, const pair<int, int> &op2)
        {
            return op1.second > op2.second;
        }
    };
};