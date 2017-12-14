//Solution 1
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {

		int perimeter = 0;

		for (int row = 0; row < grid.size(); row++) {
			for (int col = 0; col < grid[0].size(); col++) {
				if (grid[row][col] == 0) {
					continue;
				}

				if (row > 0 && row < grid.size() - 1) {
					if (grid[row - 1][col] == 0) {
						perimeter++;
					}

					if (grid[row + 1][col] == 0) {
						perimeter++;
					}
				} else if (row == 0) {
					perimeter++;
					if (grid.size() == 1) {
						perimeter++;
					} else if (grid[row + 1][col] == 0) {
						perimeter++;
					}
				} else {
					perimeter++;
					if (grid[row - 1][col] == 0) {
						perimeter++;
					}
				}

				if (col > 0 && col < grid[0].size() - 1) {
					if (grid[row][col - 1] == 0) {
						perimeter++;
					}

					if (grid[row][col + 1] == 0) {
						perimeter++;
					}
				} else if (col == 0) {
					perimeter++;
					if (grid[0].size() == 1) {
						perimeter++;
					} else if (grid[row][col + 1] == 0) {
						perimeter++;
					}
				} else {
					perimeter++;
					if (grid[row][col - 1] == 0) {
						perimeter++;
					}
				}
			}
		}

		return perimeter;
	}
};

//Solution 2
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {

		int count = 0;
        int repeat = 0;
		for (int row = 0; row < grid.size(); row++) {
			for (int col = 0; col < grid[0].size(); col++) {
				if (grid[row][col] == 0) {
					continue;
				}

				count++;
				if (col > 0 && grid[row][col - 1] == 1) {
				    repeat++;
				}
				
				if (row > 0 && grid[row - 1][col] == 1) {
				    repeat++;
				}
			}
		}

		return count * 4 - repeat * 2;
	}
};
