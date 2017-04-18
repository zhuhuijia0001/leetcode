class Solution {
public:
    string reverseString(string s) 
    {
        int size = s.size();
        int head, tail;
        
        for (head = 0, tail = size - 1; head < tail; head++, tail--)
        {
            char c = s[head];
            s[head] = s[tail];
            s[tail] = c;
        }
        
        return s;
    }
};