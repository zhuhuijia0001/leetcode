class Solution 
{
public:
    int reverse(int x) 
    {
        if (x == INT_MIN)
        {
            return 0;
        }
        
        bool negative = false;
        
        if (x < 0)
        {
            negative = true;
            
            x = -x;
        }
        
        long long r = 0;
        
        while (x)
        {
            r *= 10;
            r += x % 10;
            
            x /= 10;
        }
        
        if (r > INT_MAX)
        {
            return 0;
        }
        
        if (negative)
        {
            return -r;
        }
        
        return r;
    }
};