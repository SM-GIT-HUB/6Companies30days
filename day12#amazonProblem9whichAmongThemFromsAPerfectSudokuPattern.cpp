class Solution {
public:
    bool check(char val, int row, int col, vector<vector<char> >& grid)
    {
        for (int i = 0; i < 9; i++)
        {
            //checkrow
            if (grid[row][i] == val && i != col) {
                return false;
            }
            
            //checkcol
            if (grid[i][col] == val && i != row) {
                return false;
            }
            
            int rowindex = (row / 3) * 3 + i / 3;
            int colindex = (col / 3) * 3 + i % 3;
            
            if (grid[rowindex][colindex] == val && (rowindex != row || colindex != col)) {
                return false;
            }
        }
        
        return true;
    }

    bool solveIt(vector<vector<char> >& grid)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (grid[row][col] != '.')
                {
                    if (!check(grid[row][col], row, col, grid)) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = solveIt(board);

        return ans;
    }
};
