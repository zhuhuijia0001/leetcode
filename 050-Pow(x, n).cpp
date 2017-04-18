class Solution {
public:
    double myPow(double x, int n) 
    {
    	double res = 1;
    
    	double tmp = x;
    
    	int sign = 0;
    
    	long long m = n;
    
    	if (m < 0)
    	{
    		m = -m;
    		sign = 1;
    	}
    
    	while (m > 0)
    	{
    		if (m & 0x01)
    		{
    			res *= tmp;
    		}
    
    		tmp *= tmp;
    
    		m >>= 1;
    	}
    
    	if (sign == 1)
    	{
    		return 1 / res;
    	}
    
    	return res;
    }
};