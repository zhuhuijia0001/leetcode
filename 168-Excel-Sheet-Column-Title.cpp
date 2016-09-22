class Solution {
public:
    string convertToTitle(int n) 
    {
        int r;
        string str;
        
        while (n > 0)
        {
            n--;
            r = n % 26;
            
            n /= 26;
            
            
            str.insert(str.begin(), 'A' + r);
        }
        
        return str;
    }
};