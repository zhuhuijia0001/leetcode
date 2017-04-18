
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        
        generate(vec, "", n, n);
        
        return vec;
    }
    
private:
    void generate(vector<string> &vec, string subStr, int left, int right) {
        if (left <= right) {
            if (left > 0) {
                generate(vec, subStr + '(', left - 1, right);
            }
            
            if (right > 0) {
                generate(vec, subStr + ')', left, right - 1);
            }
            
            if (left == 0 && right == 0) {
                vec.push_back(subStr);
            }
        }
    }
};