class Solution {
public:
    bool check(vector<int>& needs)
    {
        for (int x : needs)
        {
            if (x < 0) {
                return false;
            }
        }

        return true;
    }

    int getPrice(int n, vector<int>& price, vector<int>& needs)
    {
        int p = 0;

        for (int i = 0; i < n; i++)
        {
            p += price[i] * needs[i];
        }

        return p;
    }

    string needsToString(vector<int>& needs)
    {
        string s = "";

        for (int n : needs)
        {
            s += to_string(n) + ",";
        }

        return s;
    }

    int recur(vector<int>& price, vector<vector<int> >& special, vector<int>& needs)
    {
        if (!check(needs)) {
            return 1e6;
        }

        int currPrice = getPrice(price.size(), price, needs);

        int ans = currPrice;

        for (auto &sp : special)
        {
            int n = sp.size();

            for (int i = 0; i < n - 1; i++)
            {
                needs[i] = needs[i] - sp[i];
            }

            ans = min(ans, sp[n - 1] + recur(price, special, needs));

            for (int i = 0; i < n - 1; i++)
            {
                needs[i] = needs[i] + sp[i];
            }
        }

        return ans;
    }


    int memoization(vector<int>& price, vector<vector<int> >& special, vector<int>& needs, unordered_map<string, int>& dp)
    {
        string key = needsToString(needs);

        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        if (!check(needs)) {
            return 1e6;
        }

        int currPrice = getPrice(price.size(), price, needs);

        int ans = currPrice;

        for (auto &sp : special)
        {
            int n = sp.size();

            for (int i = 0; i < n - 1; i++)
            {
                needs[i] = needs[i] - sp[i];
            }

            ans = min(ans, sp[n - 1] + memoization(price, special, needs, dp));

            for (int i = 0; i < n - 1; i++)
            {
                needs[i] = needs[i] + sp[i];
            }
        }

        return dp[key] = ans;
    }


    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // int ans = recur(price, special, needs);

        unordered_map<string, int> dp;

        int ans = memoization(price, special, needs, dp);

        return ans;
    }
};
