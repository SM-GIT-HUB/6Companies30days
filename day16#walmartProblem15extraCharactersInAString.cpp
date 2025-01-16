class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<pair<int, int> > v;

        for (auto &x : dictionary)
        {
            int pos = s.find(x);

            while (pos < s.size())
            {
                v.push_back({pos, pos + x.size() - 1});
                pos = s.find(x, pos + 1);
            }
        }

        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return (a.first < b.first);
        });

        if (v.empty()) {
            return s.size();
        }

        vector<pair<int, int> > dp(v.size(), {-1, -1});

        dp[0] = {v[0].second, v[0].second - v[0].first + 1};

        for (int i = 1; i < v.size(); i++)
        {
            int len = v[i].second - v[i].first + 1;
            int maxLen = len;

            for (int j = 0; j < i; j++)
            {
                if (dp[j].first < v[i].first) {
                    maxLen = max(dp[j].second + len, maxLen);
                }
            }

            dp[i] = {v[i].second, maxLen};
        }

        int maxi = 0;

        for (auto &p : dp)
        {
            maxi = max(p.second, maxi);
        }

        return (s.size() - maxi);
    }
};
