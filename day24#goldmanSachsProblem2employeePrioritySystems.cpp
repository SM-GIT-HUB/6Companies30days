class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        unordered_map<string, vector<int> > mapp;

        for (auto &x : access_times)
        {
            int mins = stoi(x[1].substr(0, 2)) * 60 + stoi(x[1].substr(2, 2));
            mapp[x[0]].push_back(mins);
        }

        for (auto &it : mapp)
        {
            string emp = it.first;
            sort(mapp[emp].begin(), mapp[emp].end());

            vector<int> times = mapp[emp];
            int start = 0;

            for (int i = 0; i < times.size(); i++)
            {
                while(times[i] - times[start] >= 60) {
                    start++;
                }

                if (i - start + 1 >= 3)
                {
                    ans.push_back(emp);
                    break;
                }
            }
        }

        return ans;
    }
};
