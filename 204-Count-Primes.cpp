class Solution 
{
public:
    int countPrimes(int n) 
    {
        if (n <= 2)
        {
            return 0;
        }
        
    	vector<int> vec(n);
	
    	int i, j;
    
    	int k = int(sqrt(n - 1) + 0.5);
        
    	for (i = 2; i <= n - 1; i++)
    	{
    		vec[i] = 1;
    	}
    
    	for (i = 2; i <= k; i++)
    	{
    		if (vec[i])
    		{
    			for (j = i * 2; j <= n - 1; j += i)
    			{
    				vec[j] = 0;
    			}
    		}
    	} 
    	
    	int count = 0;
    	for (i = 2; i <= n - 1; i++)
    	{
    	    if (vec[i])
    	    {
    	        count++;
    	    }
    	}
    	
    	return count;
    }
};