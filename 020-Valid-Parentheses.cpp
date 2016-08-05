class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> stk;
        
        for (string::iterator itr = s.begin(); itr != s.end(); ++itr)
        {
            if (*itr == '('
                || *itr == '{'
                || *itr == '[')
            {
                stk.push(*itr);
            }
            else if (*itr == ')')
            {
                if (stk.empty() || stk.top() != '(')
                {
                    return false;
                }
                
                stk.pop();
            }
            else if (*itr == '}')
            {
                if (stk.empty() || stk.top() != '{')
                {
                    return false;
                }
                
                stk.pop();
            }
            else if (*itr == ']')
            {
                if (stk.empty() || stk.top() != '[')
                {
                    return false;
                }
                
                stk.pop();
            }
        }
        
        if (!stk.empty())
        {
            return false;
        }
        
        return true;
    }
};