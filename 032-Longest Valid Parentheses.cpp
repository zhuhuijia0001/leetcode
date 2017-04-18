
//Solution1
class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> stk;
        
        stk.push(-1);
        
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            int index = stk.top();
            
            if (index != -1 && s[i] == ')' && s[index] == '(') {
                stk.pop();
                    
                maxLen = max(maxLen, i - stk.top());
            } else {
                stk.push(i);
            }
        }
        
        return maxLen;
    }
};

//solution2
class Solution {
public:
    int longestValidParentheses(string s) {
        
        int left = 0;
        int right = 0;
        int maxLen = 0;
        
        for (string::const_iterator itr = s.cbegin(); itr != s.cend(); ++itr) {
            if (*itr == '(') {
                left++;
            } else {
                right++;
            }
            
            if (right == left) {
                maxLen = max(maxLen, right * 2);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        
        left = 0;
        right = 0;
        for (string::const_reverse_iterator itr = s.crbegin(); itr != s.crend(); ++itr) {
            if (*itr == ')') {
                right++;
            } else {
                left++;
            }
            
            if (left == right) {
                maxLen = max(maxLen, left * 2);
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        
        return maxLen;
    }
};