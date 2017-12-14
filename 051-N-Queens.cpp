class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {

		vector<vector<string>> vecRes;
		vecRes.reserve(n);

		std::vector<int> row(n + 1), 
			a(n + 1, 1), b(n * 2 + 1, 1), c(n * 2 + 1, 1); 

		int m;

		m = 1;
		row[1] = 1;
		bool bGood = true;
		do {
			if (bGood) {
				if (m == n) {
					vector<string> vec;
					vec.reserve(n);
					for (int i = 1; i <= n; i++) {
						string str;
						for (int j = 1; j <= n; j++) {
							if (j == row[i]) {
								str.push_back('Q');
							} else {
								str.push_back('.');
							}
						}
						vec.push_back(str);
					}
					vecRes.push_back(vec);

					if (row[m] == n) {
						m--;
						a[row[m]] = b[m + row[m]] = c[n + m - row[m]] = 1;
					}
					row[m]++;
				} else {
					a[row[m]] = b[m + row[m]] = c[n + m - row[m]] = 0;
					row[++m] = 1;
				}
			} else {
				while (m > 0 && row[m] == n) {
					m--;
					a[row[m]] = b[m + row[m]] = c[n + m - row[m]] = 1;
				}
				row[m]++;
			}

			bGood = a[row[m]] && b[m + row[m]] && c[n + m - row[m]];
		} while (m > 0);

		return vecRes;
	}
};
