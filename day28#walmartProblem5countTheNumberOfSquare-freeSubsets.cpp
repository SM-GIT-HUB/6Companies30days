class Solution {
public:
    int mod = 1000000007;
    int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int primeMasks[31] = {0};
    vector<vector<int> > dp;

    void getPrimeMasks()
    {
        for (int i = 2; i <= 30; i++)
        {
            int mask = 0;
            int flag = 0;

            for (int j = 0; j < 10 && primes[j] <= i; j++)
            {
                if (i % (primes[j] * primes[j]) == 0)
                {
                    flag = 1;
                    break;
                }

                if (i % primes[j] == 0) {
                    mask = mask | (1 << j);
                }
            }

            if (flag) {
                primeMasks[i] = -1;
            }
            else
                primeMasks[i] = mask;
        }
    }

    bool canInclude(int mask1, int mask2)
    {
        return (mask1 & mask2) == 0;
    }

    int recur(int index, int n, int mask, vector<int>& nums)
    {
        if (index >= n) {
            return 1;
        }

        long long exclude = recur(index + 1, n, mask, nums) % mod;
        long long include = 0;

        if (primeMasks[nums[index]] != -1 && ((mask & primeMasks[nums[index]]) == 0)) {
            include = recur(index + 1, n, mask | primeMasks[nums[index]], nums) % mod;
        }

        return (include + exclude) % mod;
    }


    int memoization(int index, int n, int mask, vector<int>& nums)
    {
        if (index >= n) {
            return 1;
        }

        if (dp[index][mask] != -1) {
            return dp[index][mask] % mod;
        }

        long long exclude = memoization(index + 1, n, mask, nums) % mod;
        long long include = 0;

        if (primeMasks[nums[index]] != -1 && ((mask & primeMasks[nums[index]]) == 0)) {
            include = memoization(index + 1, n, mask | primeMasks[nums[index]], nums) % mod;
        }

        return dp[index][mask] = (include + exclude) % mod;
    }


    int tabulation(int n, vector<int>& nums)
    {
        for (int index = n - 1; index >= 0; index--)
        {
            for (int mask = (1 << 10) - 1; mask >= 0; mask--)
            {
                dp[n][mask] = 1;

                long long exclude = dp[index + 1][mask] % mod;
                long long include = 0;

                if (primeMasks[nums[index]] != -1 && ((mask & primeMasks[nums[index]]) == 0)) {
                    include = dp[index + 1][mask | primeMasks[nums[index]]] % mod;
                }

                dp[index][mask] = (include + exclude) % mod;
            }
        }

        return dp[0][0];
    }


    int spaceOpt(int n, vector<int>& nums)
    {
        vector<int> next(1025, 0);
        vector<int> curr(1025, 0);
 
        for (int index = n - 1; index >= 0; index--)
        {
            for (int mask = (1 << 10) - 1; mask >= 0; mask--)
            {
                if (index == n - 1) {
                    next[mask] = 1;
                }

                long long exclude = next[mask] % mod;
                long long include = 0;

                if (primeMasks[nums[index]] != -1 && ((mask & primeMasks[nums[index]]) == 0)) {
                    include = next[mask | primeMasks[nums[index]]] % mod;
                }

                curr[mask] = (include + exclude) % mod;
            }

            next = curr;
        }

        return next[0];
    }


    int squareFreeSubsets(vector<int>& nums) {
        getPrimeMasks();
        int n = nums.size();

        // int ans = recur(0, n, 0, nums);
        
        // dp = vector<vector<int> >(n + 1, vector<int>(1025, 0));
        
        // int ans = memoization(0, n, 0, nums);

        // int ans = tabulation(n, nums);

        int ans = spaceOpt(n, nums);

        return (ans - 1 + mod) % mod;
    }
};
