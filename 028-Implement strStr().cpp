
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (needle.empty()) {
            return 0;
        }
        
        int index1 = 0;
        int index2 = 0;
        
        while (index1 < haystack.size() && index2 < needle.size()) {
            
            if (haystack[index1] == needle[index2]) {
                index1++;
                index2++;
            } else {
                index1 -= index2 - 1; 
                index2 = 0;
            }
        }
        
        if (index2 == needle.size()) {
            return index1 - index2;
        }
        
        return -1;
    }
};