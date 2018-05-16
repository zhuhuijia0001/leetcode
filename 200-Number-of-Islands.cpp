//solution 1
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
    
private:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }
        
        if (grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};

//solution 2
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (bfs(grid, i, j)) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
private:
    bool bfs(vector<vector<char>> &grid, int i, int j) {
        if (grid[i][j] == '0') {
            return false;
        }
        
        const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        queue<pair<int, int>> q;
        q.push({i, j});
        
        grid[i][j] = '0';
        
        while (!q.empty()) {
            auto p = q.front(); q.pop();

            for (int k = 0; k < 4; k++) {
                int r = p.first + dir[k][0];
                int c = p.second + dir[k][1];
                
                if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0') {
                    continue;
                }
                
                q.push({r, c});
                grid[r][c] = '0';
            }
        }
        
        return true;
    }
};