
//Solution 1
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
    	priority_queue<int, vector<int>, greater<int> > pq(nums.begin(), nums.begin() + k);
    
    	for (auto itr = nums.begin() + k; itr != nums.end(); ++itr)
    	{
    		if (*itr > pq.top())
    		{
    		    pq.pop();
    		    
    		    pq.push(*itr);
    		}
    	}
    
    	return pq.top();
    }
};


//Solution 2
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
	{
		int low = 0;
		int high = nums.size() - 1;
        
        int index = 0;
        
		while (low <= high)
		{
			index = partition(nums, low, high); 

			if (index > k - 1)
			{
				high = index - 1;
			}
			else if (index < k - 1)
			{
				low = index + 1;
			}
			else
			{
				break;
			}
		}

		return nums[index];
	}
	
private:
    int partition(vector<int>& nums, int low, int high)
	{
		int pivot = nums[low];
		
		int storeIndex = low;
		for(int i = low + 1; i <= high; ++i) 
		{
			if(nums[i] > pivot) 
			{
			    ++storeIndex;
			    if (i != storeIndex)
			    {
				    swap(nums[i], nums[storeIndex]);
			    }
			}
		}

        if (storeIndex != low)
        {
		    swap(nums[storeIndex], nums[low]);
        }

		return storeIndex;
	}
};

//Solution 3
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        
        return nums[k - 1];
	}
};
