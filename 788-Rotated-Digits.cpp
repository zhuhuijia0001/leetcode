class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        
        for (int i = 2; i <= N; i++) {
            if (isGoodNum(i)) {
                count++;
            }
        }
        
        return count;
    }
    
private:
    bool isGoodNum(int n) {
        
        bool same = true;
        while (n > 0) {
            
            int r = n % 10;
            n /= 10;
            
            int a = kMap[r];
            if (a < 0) {
                return false;
            }
            
            if (r != a) {
                same = false;
            }
        }
    
        return !same;
    }
    
private:
    static vector<int> kMap;
};

vector<int> Solution::kMap = { 0, 1, 5, -1, -1, 2, 9, -1, 8, 6 }; 
