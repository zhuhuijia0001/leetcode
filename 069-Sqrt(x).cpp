class Solution {
public:
	int mySqrt(int x) {
	    if (x <= 1)
	        return x;
	        
		int low = 0, high = x;

		while (low <= high) {
			long mid = (high - low) / 2 + low;

			if (mid * mid == x) {
				return mid;
			} else if (mid * mid > x) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return high;
	}
};