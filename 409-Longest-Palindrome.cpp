class Solution {
public:
    int longestPalindrome(string s) {
        
        int lowerMap[26];
        int upperMap[26];
        memset(lowerMap, 0, sizeof(lowerMap));
        memset(upperMap, 0, sizeof(upperMap));
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                lowerMap[s[i] - 'a']++;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                upperMap[s[i] - 'A']++;
            }
        }
        
        int maxLen = 0;
        bool bOdd = false;
        for (int i = 0; i < 26; i++) {
            if ((lowerMap[i] & 0x01) == 0) {
                maxLen += lowerMap[i];
            } else {
                bOdd = true;
                
                maxLen += lowerMap[i] - 1;
            }
            
            if ((upperMap[i] & 0x01) == 0) {
                maxLen += upperMap[i];
            } else {
                bOdd = true;
                
                maxLen += upperMap[i] - 1;
            }
        }
        
        if (bOdd) {
            maxLen++;
        }
        
        return maxLen;
    }
};