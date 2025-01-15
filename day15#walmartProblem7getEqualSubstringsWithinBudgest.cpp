class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int total = 0;

        int ans = 0;
        int start = 0, end = 0;

        total += abs(s[0] - t[0]);

        while (end < n)
        {
            while (total > maxCost)
            {
                total -= abs(s[start] - t[start++]);
            }

            ans = max(end - start + 1, ans);
            end++;

            if (end >= n) {
                break;
            }

            total += abs(s[end] - t[end]);
        }

        return ans;
    }
};
