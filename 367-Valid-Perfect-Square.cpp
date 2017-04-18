class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        
        while (low <= high) {
            long mid = (high - low) / 2 + low;
            
            if (mid * mid == num) {
                return true;
            } else if (mid * mid > num) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return false;
    }
};