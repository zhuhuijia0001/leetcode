class Solution {
public:
	int totalNQueens(int n) {
		std::vector<int> row(n + 1), 
			a(n + 1, 1), b(n * 2 + 1, 1), c(n * 2 + 1, 1); 

		int count = 0;

		int m;

		m = 1;
		row[1] = 1;
		bool bGood = true;
		do {
			if (bGood) {
				if (m == n) {
					count++;

					while (m > 0 && row[m] == n) {
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

		return count;
	}
};
