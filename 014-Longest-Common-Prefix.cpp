class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string str;
        
        if (!strs.empty())
        {
            int minLen = strs[0].size();
            
            for (int i = 1; i < strs.size(); i++)
            {
                if (minLen > strs[i].size())
                {
                    minLen = strs[i].size();
                }
            }
            
            for (int i = 0; i < minLen; i++)
            {
                for (int j = 1; j < strs.size(); j++)
                {
                    if (strs[j][i] != strs[0][i])
                    {
                        goto OUT;
                    }
                }
                
                str.push_back(strs[0][i]);
            }
        }
        
 OUT:       
        return str;
    }
};
