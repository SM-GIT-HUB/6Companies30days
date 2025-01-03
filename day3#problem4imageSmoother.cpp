class Solution {
public:
    bool pos(int x, int y, int rows, int cols)
    {
        return (x >= 0 && x < rows && y >= 0 && y < cols);
    }

    int getAns(int x, int y, int rows, int cols, vector<vector<int> >& pairs, vector<vector<int> >& img)
    {
        float total = img[x][y];
        float num = 1;

        for (auto &p : pairs)
        {
            if (pos(x + p[0], y + p[1], rows, cols))
            {
                total += img[x + p[0]][y + p[1]];
                num++;
            }
        }

        return (int)(total / num);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();

        vector<vector<int> > pairs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

        vector<vector<int> > ans(rows, vector<int>(cols, 0));

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                ans[row][col] = getAns(row, col, rows, cols, pairs, img);
            }
        }

        return ans;
    }
};
