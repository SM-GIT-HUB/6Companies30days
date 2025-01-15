class Solution {
public:
    bool check(int x, int y, int rows, int cols, vector<vector<char> >& board)
    {
        if (x > 0 && board[x - 1][y] == 'X') {
            return false;
        }

        if (y > 0 && board[x][y - 1] == 'X') {
            return false;
        }

        return true;
    }

    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int ans = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (board[row][col] == 'X')
                {
                    if (check(row, col, rows, cols, board)) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
