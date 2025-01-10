class Solution {
public:
    int recur(int index, int n, int count, int k, vector<int>& prices)
    {
        if (index >= n || count >= k) {
            return 0;
        }

        int ans = 0;

        if (count % 2 == 0)
        {
            int include = -prices[index] + recur(index + 1, n, count + 1, k, prices);
            int exclude = 0 + recur(index + 1, n, count, k, prices);

            ans = max(include, exclude);
        }
        else
        {
            int include = prices[index] + recur(index + 1, n, count + 1, k, prices);
            int exclude = 0 + recur(index + 1, n, count, k, prices);

            ans = max(include, exclude);
        }

        return ans;
    }


    int memoization(int index, int n, int count, int k, vector<int>& prices, vector<vector<int> >& dp)
    {
        if (index >= n || count >= k) {
            return 0;
        }

        if (dp[index][count] != -1) {
            return dp[index][count];
        }

        int ans = 0;

        if (count % 2 == 0)
        {
            int include = -prices[index] + memoization(index + 1, n, count + 1, k, prices, dp);
            int exclude = 0 + memoization(index + 1, n, count, k, prices, dp);

            ans = max(include, exclude);
        }
        else
        {
            int include = prices[index] + memoization(index + 1, n, count + 1, k, prices, dp);
            int exclude = 0 + memoization(index + 1, n, count, k, prices, dp);

            ans = max(include, exclude);
        }

        return dp[index][count] = ans;
    }


    int tabulation(int n, int k, vector<int>& prices)
    {
        vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int count = k - 1; count >= 0; count--)
            {
                int ans = 0;

                if (count % 2 == 0)
                {
                    int include = -prices[index] + dp[index + 1][count + 1];
                    int exclude = 0 + dp[index + 1][count];

                    ans = max(include, exclude);
                }
                else
                {
                    int include = prices[index] + dp[index + 1][count + 1];
                    int exclude = 0 + dp[index + 1][count];

                    ans = max(include, exclude);
                }

                dp[index][count] = ans;
            }
        }
        
        return dp[0][0];
    }


    int spaceOpt(int n, int k, vector<int>& prices)
    {
        vector<int> next(k + 1, 0);
        vector<int> curr(k + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int count = k - 1; count >= 0; count--)
            {
                int ans = 0;

                if (count % 2 == 0)
                {
                    int include = -prices[index] + next[count + 1];
                    int exclude = 0 + next[count];

                    ans = max(include, exclude);
                }
                else
                {
                    int include = prices[index] + next[count + 1];
                    int exclude = 0 + next[count];

                    ans = max(include, exclude);
                }

                curr[count] = ans;
            }

            next = curr;
        }
        
        return next[0];
    }


    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // int ans = recur(0, n, 0, 2 * k, prices);

        // vector<vector<int> > dp(n, vector<int>(2 * k, -1));

        // int ans = memoization(0, n, 0, 2 * k, prices, dp);

        // int ans = tabulation(n, 2 * k, prices);

        int ans = spaceOpt(n, 2 * k, prices);

        return ans;
    }
};
