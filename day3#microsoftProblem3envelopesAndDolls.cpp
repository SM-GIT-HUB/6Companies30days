class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b)
    {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }

        return (a[0] < b[0]);
    }

    void binSearch(vector<int>& ans, int x)
    {
        int start = 0, end = ans.size();

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (x > ans[mid]) {
                start = mid + 1;
            }
            else
                end = mid - 1;
        }

        ans[start] = x;
    }

    int dpBisearch(vector<vector<int>>& env)
    {
        int n = env.size();
        vector<int> ans;

        ans.push_back(env[0][1]);

        for (int i = 1; i < n; i++)
        {
            if (env[i][1] > ans[ans.size() - 1]) {
                ans.push_back(env[i][1]);
            }
            else
                binSearch(ans, env[i][1]);
        }

        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);

        int ans = dpBisearch(envelopes);

        return ans;
    }
};
