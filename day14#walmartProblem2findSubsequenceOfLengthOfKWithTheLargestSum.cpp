class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

        for (int i = 0; i < n; i++)
        {
            if (i < k) {
                q.push({nums[i], i});
            }
            else
            {
                if (q.top().first < nums[i])
                {
                    q.pop();
                    q.push({nums[i], i});
                }
            }
        }

        vector<pair<int, int> > temp;

        while (!q.empty())
        {
            temp.push_back(q.top());
            q.pop();
        }

        sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return (a.second < b.second);
        });

        vector<int> ans;

        for (auto &p : temp)
        {
            ans.push_back(p.first);
        }

        return ans;
    }
};
