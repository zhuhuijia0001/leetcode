class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if (s.empty()) {
            return true;
        }
        
        int index = 0;
        
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == s[index]) {
                if (index == s.length() - 1) {
                    return true;
                }
                
                index++;
            }
        }
        
        return false;
    }
};