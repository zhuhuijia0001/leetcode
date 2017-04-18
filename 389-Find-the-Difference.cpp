class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int count[26];
        memset(count, 0, sizeof(count));
        
        for (int i = 0; i < t.length(); i++) {
            count[t[i] - 'a']++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']--;
        }
        
        char res = '\0';
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                res = i + 'a';
            }
        }
        
        return res;
    }
};