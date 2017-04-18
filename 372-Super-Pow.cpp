class Solution {
public:
    int superPow(int a, vector<int>& b) {
        
        int res = 1;
        int mod = 1337;
        
        for (auto n : b) {
            res = my_power(res, 10, mod);
            res *= my_power(a, n, mod);
            res %= mod;
        }
        
        return res;
    }
    
private:
    int my_power(int a, int n, int mod) {
		int res = 1;

		while (n > 0) {
		    a %= mod;
		    
			if (n & 0x01) {
				res *= a;
				
				res %= mod;
			}

			a *= a;

			n >>= 1;
		}

		return res;
	}
};