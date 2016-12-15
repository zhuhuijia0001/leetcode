class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string res;
        
        int len1 = num1.length();
        int len2 = num2.length();
        
        int c = 0;
        int i;
        for (i = 0; i < len1 && i < len2; i++) {
            int sum = num1[len1 - 1 - i] - '0' + num2[len2 - 1 - i] - '0' + c;
            
            c = 0;
            if (sum >= 10) {
                sum -= 10;
                c++;
            }
            
            res.push_back('0' + sum);
        }
        
        for ( ; i < len1; i++) {
            int sum = num1[len1 - 1 - i] - '0' + c;
            
            c = 0;
            if (sum >= 10) {
                sum -= 10;
                c++;
            } 
            
            res.push_back('0' + sum);
        }
        
        for ( ; i < len2; i++) {
            int sum = num2[len2 - 1 - i] - '0' + c;
            
            c = 0;
            if (sum >= 10) {
                sum -= 10;
                c++;
            } 
            
            res.push_back('0' + sum);
        }
        
        if (c > 0) {
            res.push_back('1');
        }
        
        for (int i = 0, j = res.length() - 1; i < j; i++, j--) {
            swap(res[i], res[j]);
        }
        
        return res;
    }
};