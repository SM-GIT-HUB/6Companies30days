class Solution {
public:
    void dfs(int row, int col, int rows, int cols, vector<vector<bool>>& visited, vector<vector<int>>& grid)
    {
        if (row < 0 || col < 0 || row >= rows || col >= cols || visited[row][col] || grid[row][col] == 0) {
            return;
        }
        
        visited[row][col] = true;
        
        dfs(row - 1, col, rows, cols, visited, grid);
        dfs(row + 1, col, rows, cols, visited, grid);
        dfs(row, col - 1, rows, cols, visited, grid);
        dfs(row, col + 1, rows, cols, visited, grid);
    }

    int checkConnection(vector<vector<int>>& grid, int rows, int cols)
    {
        int count = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (grid[row][col] == 1 && !visited[row][col])
                {
                    dfs(row, col, rows, cols, visited, grid);
                    count++;
                }
            }
        }
        
        return count;
    }


    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = checkConnection(grid, rows, cols);

        if (count != 1) {
            return 0;
        }

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 1)
                {
                    grid[row][col] = 0;

                    count = checkConnection(grid, rows, cols);

                    if (count != 1) {
                        return 1;
                    }

                    grid[row][col] = 1;
                }
            }
        }

        for (int row1 = 0; row1 < rows; row1++)
        {
            for (int col1 = 0; col1 < cols; col1++)
            {
                if (grid[row1][col1] == 1)
                {
                    grid[row1][col1] = 0;

                    for (int row2 = 0; row2 < rows; row2++)
                    {
                        for (int col2 = 0; col2 < cols; col2++)
                        {
                            if (grid[row2][col2] == 1)
                            {
                                grid[row2][col2] = 0;
                                
                                count = checkConnection(grid, rows, cols);

                                if (count != 1) {
                                    return 2;
                                }

                                grid[row2][col2] = 0;
                            }
                        }
                    }

                    grid[row1][col1] = 1;
                }
            }
        }

        return 2;
    }
};
