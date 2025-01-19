class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        vector<long long> lps(n, 0);
        
        long long len = 0, index = 1;
        
        while (index < n)
        {
            if (s[len] == s[index]) {
                lps[index++] = ++len;
            }
            else if (len == 0) {
                lps[index++] = len;
            }
            else
                len = lps[len - 1];
        }

        long long ans = 0;
        
        vector<long long> count;

        for (long long x : lps)
        {
            count.push_back(x == 0? 0 : count[x - 1] + 1);
            ans += count[count.size() - 1];
        }

        ans += n;

        return ans;
    }
};
