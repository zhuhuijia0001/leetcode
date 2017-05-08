class Solution {
public:
    bool isHappy(int n) 
    {
        vector<int> vec;
        
        vec.push_back(n);
        
        while (true)
        {
            n = getSquareSum(n);
            if (n == 1)
            {
                break;
            }
            
            auto itr = find(vec.begin(), vec.end(), n);
            if (itr != vec.end())
            {
                return false;
            }
            
            vec.push_back(n);
        }
        
        return true;
    }
    
private:
    int getSquareSum(int n)
    {
        int sum = 0;
        
        while (n > 0)
        {
            int r = n % 10;
            
            sum += r * r;
            
            n /= 10;
        }
        
        return sum;
    }
};