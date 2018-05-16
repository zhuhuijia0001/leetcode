
//solution 1
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int row = board.size();
        if (row == 0) {
            return;
        }
        
        int col = board[0].size();
        
        for (int i = 0; i < row; i++) {
            fill(board, i, 0);
            
            fill(board, i, col - 1);
        }
        
        for (int i = 0; i < col; i++) {
            fill(board, 0, i);
            
            fill(board, row - 1, i);
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
private:
    void fill(vector<vector<char>> &board, int row, int col) {
        if (board[row][col] != 'O') {
            return;
        }
        
        board[row][col] = '#';
        
        queue<pair<int, int>> q;
        q.push({ row, col });
        
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            
            int r = p.first;
            int c = p.second;
            
            if (r >= 1 && board[r - 1][c] == 'O') {
                board[r - 1][c] = '#';
                
                q.push({r - 1, c});
            }
            
            if (r + 1 < board.size() && board[r + 1][c] == 'O') {
                board[r + 1][c] = '#';
                
                q.push({r + 1, c});
            }
            
            if (c >= 1 && board[r][c - 1] == 'O') {
                board[r][c - 1] = '#';
                
                q.push({r, c - 1});
            }
            
            if (c + 1 < board[0].size() && board[r][c + 1] == 'O') {
                board[r][c + 1] = '#';
                
                q.push({r, c + 1});
            }
        }
    }
};

//solution 2
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int row = board.size();
        if (row == 0) {
            return;
        }
        
        int col = board[0].size();
        
        for (int i = 0; i < row; i++) {
            fill(board, i, 0);
            
            fill(board, i, col - 1);
        }
        
        for (int i = 0; i < col; i++) {
            fill(board, 0, i);
            
            fill(board, row - 1, i);
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
private:
    void fill(vector<vector<char>> &board, int row, int col) {
        
        if (row < 0 || row >= board.size()
           || col < 0 || col >= board[0].size()) {
            return;
        }
        
        if (board[row][col] != 'O') {
            return;
        }
        
        board[row][col] = '#';
        
        fill(board, row - 1, col);
        fill(board, row + 1, col);
        fill(board, row, col - 1);
        fill(board, row, col + 1);
    }
};
