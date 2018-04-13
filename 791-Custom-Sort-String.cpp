class Solution {
public:
    string customSortString(string S, string T) {
        
        vector<int> bucket(26, 0);
        
        for (auto c : T) {
            bucket[c - 'a']++;
        }
        
        string str;
        
        for (auto c : S) {
            while (bucket[c - 'a'] > 0) {
                str.push_back(c);
                
                bucket[c - 'a']--;
            }
        }
        
        for (auto c : T) {
            while (bucket[c - 'a'] > 0) {
                str.push_back(c);
                
                bucket[c - 'a']--;
            }
        }
        
        return str;
    }
};
