class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int>::reverse_iterator itr;
        
        for (itr = digits.rbegin(); itr != digits.rend(); ++itr)
        {
            if ((*itr) < 9)
            {
                *itr += 1;
                
                return digits;
            }
            else
            {
                *itr = 0;
            }
        }

        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};