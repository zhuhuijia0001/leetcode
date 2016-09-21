//Solution 1
class Solution {
public:
    string longestPalindrome(string s) {
        
		int n = s.size();

        int max = 1;
        int start = 0;
        
		bool dp[1000][1000] = { false };
		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}

		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1]) {
				dp[i][i + 1] = true;

				start = i;
				max = 2;
			}
		}
        
		for (int len = 3; len <= n; len++) {
			for (int i = 0; i < n - len + 1; i++) {
				int j = i + len - 1;

				if (s[i] == s[j] && dp[i + 1][j - 1]) {
					dp[i][j] = true;

					start = i;
					max = len;
				}
			}
		}
        
        return s.substr(start, max);
    }
};


//Solution 2
class Solution {
public:
    string longestPalindrome(string s) {
        
        int max = 0;
        string longest = "";
        
        int len = s.length();
        for (int i = 0; i < len; i++) {
            string substr = getMaxPalindromeFromCenter(s, i, i);
            
            if (max < substr.length()) {
                max = substr.length();
                
                longest = substr;
            }
            
            if (i + 1 < len) {
                substr = getMaxPalindromeFromCenter(s, i, i + 1);
                
                if (max < substr.length()) {
                    max = substr.length();
                    
                    longest = substr;
                }
            }
        }
        
        return longest;
    }
    
private:
    string getMaxPalindromeFromCenter(string s, int leading, int trailing) {
        
        int len = s.length();
        while (leading >= 0 && trailing < len) {
            if (s[leading] != s[trailing]) {
                break;
            }
            
            leading--;
            trailing++;
        }
        
        leading++;
        trailing--;
        
        return s.substr(leading, trailing - leading + 1);
    }
};