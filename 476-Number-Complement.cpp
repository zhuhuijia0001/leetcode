class Solution {
public:
    int findComplement(int num) {
        
        int mask = 0x80000000;
        
        while ((mask & num) == 0) {
            mask >>= 1;
        }
        
        num |= mask;
        
        return ~num;
    }
};