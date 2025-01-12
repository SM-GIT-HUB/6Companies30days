class Solution {
public:
    string getString(int col)
    {
        if (col == 0) {
            return "";
        }

        if (col < 27) {
            return string(1, col - 1 + 'A');
        }

        string ans = "";

        if (col % 26 == 0)
        {
            ans = getString((col - 1) / 26);
            int curr = (col - 1) % 26 + 1;

            ans += string(1, curr - 1 + 'A');
        }
        else
        {
            ans = getString(col / 26);
            int curr = col % 26;

            ans += string(1, curr - 1 + 'A');
        }

        return ans;
    }

    string convertToTitle(int columnNumber) {
        int col = columnNumber;

        if (col <= 26) {
            return string(1, col - 1 + 'A');
        }

        string ans = getString(col);

        return ans;
    }
};
