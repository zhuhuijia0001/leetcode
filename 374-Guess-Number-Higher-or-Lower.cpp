// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        
        int low, high;
        
        int mid;
        
        low = 1;
        high = n;
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            
            int ret = guess(mid);
            if (ret < 0) {
                high = mid - 1;
            } else if (ret > 0) {
                low = mid + 1;
            } else {
                break;
            }
        }
        
        return mid;
    }
};