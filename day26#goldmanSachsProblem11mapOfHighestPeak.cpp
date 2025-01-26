class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        queue<pair<int, int> > q;

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (isWater[row][col] == 0) {
                    isWater[row][col] = -1;
                }
                else
                {
                    q.push({row, col});
                    isWater[row][col] = 0;
                }
            }
        }

        vector<vector<int> > dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            pair<int, int> top = q.front();
            q.pop();

            int i = top.first;
            int j = top.second;
            int val = isWater[i][j];

            for (auto &x : dirs)
            {
                int ni = i + x[0];
                int nj = j + x[1];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n && isWater[ni][nj] == -1)
                {
                    isWater[ni][nj] = val + 1;
                    q.push({ni, nj});
                }
            }
        }

        return isWater;
    }
};
