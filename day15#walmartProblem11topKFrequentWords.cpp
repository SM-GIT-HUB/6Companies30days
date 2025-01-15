class Solution {
public:
    class comp {
    public:
        bool operator()(pair<int, string>& a, pair<int, string>& b)
        {
            if (a.first == b.first) {
                return (a.second < b.second);
            }

            return (a.first > b.first);
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;

        for (string &x : words)
        {
            count[x]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string> >, comp> q;

        for (auto &it : count)
        {
            if (q.size() < k) {
                q.push({it.second, it.first});
            }
            else
            {
                if (q.top().first == it.second)
                {
                    if (it.first < q.top().second)
                    {
                        q.pop();
                        q.push({it.second, it.first});
                    }
                }
                else if (q.top().first < it.second)
                {
                    q.pop();
                    q.push({it.second, it.first});
                }
            }
        }

        vector<string> ans;

        while (!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
