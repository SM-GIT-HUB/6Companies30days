class Solution {
public:
    void track(int index, int n, string *s, string &digits, string &output, vector<string>& ans)
    {
        if (index >= n)
        {
            ans.push_back(output);
            return;
        }

        int curr = digits[index] - '0';

        for (char x : s[curr])
        {
            output += x;
            track(index + 1, n, s, digits, output, ans);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }

        string s[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string output;

        track(0, digits.size(), s, digits, output, ans);

        return ans;
    }
};
