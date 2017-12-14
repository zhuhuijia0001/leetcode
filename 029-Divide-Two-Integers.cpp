class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0
			|| (dividend == INT_MIN && divisor == -1)) {
			return INT_MAX;
		}

		bool sign = (dividend < 0) ^ (divisor < 0) ? true : false;

		long long dvd = llabs(dividend);
		long long dvs = llabs(divisor);

		int res = 0;
		while (dvd >= dvs) {

			long long temp = dvs;
			int multi = 1;
			while (dvd >= (temp << 1)) {
				temp <<= 1;

				multi <<= 1;
			}
			dvd -= temp;

			res += multi;
		}

		return sign ? -res : res;
	}
};
