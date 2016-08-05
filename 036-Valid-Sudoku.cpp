bool isValidSudoku(char** board, int boardRowSize, int boardColSize) 
{
    int map_row[9][9];
    int map_col[9][9];
    int map_cell[9][9];
    
    memset(map_row, 0, sizeof(map_row));
    memset(map_col, 0, sizeof(map_col));
    memset(map_cell, 0, sizeof(map_cell));
    
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (board[i][j] >= '1' && board[i][j] <= '9')
            {
                if (map_row[i][board[i][j] - '1'] == 1
                    || map_col[j][board[i][j] - '1'] == 1
                    || map_cell[i / 3 * 3 + j / 3][board[i][j] - '1'] == 1)
                {
                    return false;
                }
                
                map_row[i][board[i][j] - '1'] = 1;
                map_col[j][board[i][j] - '1'] = 1;
                map_cell[i / 3 * 3 + j / 3][board[i][j] - '1'] = 1;
            }
        }
    }
                    
    return true;
}