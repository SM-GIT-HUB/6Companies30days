class Solution {
    int mod = 1000000007;
public:
    int ncr(long long n, int r)
    {
        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            curr[0] = 1;

            if (i <= r) {
                curr[i] = 1;
            }

            for (int j = 1; j <= min(i, r); j++)
            {
                if (i == j) {
                    curr[j] = 1;
                }
                else
                    curr[j] = (prev[j - 1] + prev[j]) % mod;
            }

            prev = curr;
        }

        return curr[r];
    }

    int numberOfWays(int startPos, int endPos, int k) {
        int diff = abs(endPos - startPos);
        long long r = (k + diff) / 2;

        if ( ((diff + k) & 1) || (k < diff)) {
            return 0;
        }

        int ans = ncr(k, r);

        return ans;
    }
};
