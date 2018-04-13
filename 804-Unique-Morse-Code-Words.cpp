class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",                                       ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
            ".--", "-..-", "-.--", "--.."};
        
        unordered_set<string> set;
        
        for (auto &str : words) {
            string s = "";
            
            for (auto c : str) {
                s += code[c - 'a'];
            }
            
            set.insert(s);
        }
        
        return set.size();
    }
};
