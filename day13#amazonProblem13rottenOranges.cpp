class Solution {
public:
    bool valid(int x, int y, int rows, int cols, vector<vector<int>>& grid)
    {
        return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int> > ops = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        queue<vector<int> > q;
        int count = 0;
        
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                }
                else if (grid[row][col] == 1) {
                    count++;
                }
            }
        }

        if (!count) {
            return 0;
        }

        if (q.empty() && count) {
            return -1;
        }

        int mins = 0;
        q.push({});

        while (!q.empty())
        {
            vector<int> top = q.front();
            q.pop();

            if (!top.size())
            {
                if (q.empty()) {
                    break;
                }
                else
                {
                    q.push({});
                    mins++;
                    continue;
                }
            }

            for (auto &v : ops)
            {
                int x = top[0] + v[0];
                int y = top[1] + v[1];

                if (valid(x, y, rows, cols, grid))
                {
                    grid[x][y] = 2;
                    q.push({x, y});
                    count--;
                }
            }
        }

        if (count) {
            return -1;
        }

        return mins;
    }
};
