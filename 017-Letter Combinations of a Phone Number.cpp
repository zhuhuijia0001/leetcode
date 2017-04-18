
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static const vector<string> MAP = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        
        result.push_back("");
        
        for (int i = 0; i < digits.length(); i++) {
            
            char c = digits[i];
            
            const string &candidate = MAP[c - '0'];
            if (candidate.empty()) {
                continue;
            }
            
            vector<string> tmp;
            for (string a : result) {
                for (char b : candidate) {
                    tmp.push_back(a + b);
                }
            }
            
            result.swap(tmp);
        }
        
        return result;
    }
};