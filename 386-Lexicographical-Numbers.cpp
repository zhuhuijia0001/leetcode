//Solution 1
class Solution {

public:
	vector<int> lexicalOrder(int n) {
		vector<int> vec;
		vec.reserve(n);

		int number = 1;

		for (int i = 1; i <= n; i++) {
			vec.push_back(number);

			if (number * 10 <= n) {
				number *= 10;
			} else {
				number++;
				while (number % 10 == 0) {
					number /= 10;
				}

				if (number > n) {
					number /= 10;

					number++;
				}
			}
		}

		return vec;
	}
};

//Solution 2
class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<int> vec;
		vec.reserve(n);

		for (int i = 1; i < 10; i++) {
			dfs(i, n, vec);
		}

		return vec;
	}

private:
	void dfs(int cur, int n, vector<int> &res) {
		if (cur <= n) {
			res.push_back(cur);

			for (int i = 0; i < 10; i++) {
				if (cur * 10 + i <= n) {
					dfs(cur * 10 + i, n, res);
				}
			}
		}
	}
};

