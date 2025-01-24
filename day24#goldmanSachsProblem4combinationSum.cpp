class Solution {
public:
    void track(int index, int total, int k, int sum, vector<int>& output, vector<vector<int> >& ans)
    {
        if (index == 10)
        {
            if (total == k && sum == 0) {
                ans.push_back(output);
            }

            return;
        }

        if (sum == 0 && total == k)
        {
            ans.push_back(output);
            return;
        }

        if (sum < 0) {
            return;
        }

        for (int i = index; i < 10; i++)
        {
            output.push_back(i);
            track(i + 1, total + 1, k, sum - i, output, ans);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> output;

        track(1, 0, k, n, output, ans);

        return ans;
    }
};
