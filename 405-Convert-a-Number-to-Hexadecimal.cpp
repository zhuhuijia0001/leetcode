class Solution {
public:
    string toHex(int num) {
        
        string s;
        
        char c;
        
        long data = num;
        if (data < 0) {
            data += 0x100000000;
        }

        if (data > 0) {
            while (data > 0) {
                int r = data % 16;
                data /= 16;
                if (r >= 0 && r < 10) {
                    c = '0' + r;
                } else {
                    c = r - 10 + 'a';
                }
                
                s.insert(s.begin(), c);
            }
        } else {
            s = "0";
        }
        
        
        return s;
    }
};