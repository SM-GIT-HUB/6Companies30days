class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();

        for(auto &x : queries)
        {
            int kth = x[0];
            int trim = x[1];

            priority_queue<pair<string, int> > q;

            for(int i = 0; i < n; i++)
            {
                string curr = nums[i].substr(nums[i].size() - trim);

                if (q.size() < kth) {
                    q.push({curr, i});
                }
                else
                {
                    if (q.top().first > curr)
                    {
                        q.pop();
                        q.push({curr, i});
                    }
                }
            }

            ans.push_back(q.top().second);
        }

        return ans;
    }
};
