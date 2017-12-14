class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> vec;
		vec.reserve(n);

		vector<int> index(primes.size(), 0);

		vector<int> values(primes);

		vec.push_back(1);
		for (int i = 1; i < n; i++) {
			int min = *min_element(values.begin(), values.end());
			vec.push_back(min);

			for (int j = 0; j < values.size(); j++) {
				if (min == values[j]) {
					values[j] = vec[++index[j]] * primes[j];
				}
			}
		}

		return vec.back();     
	}
};
