class Solution {
public:
    string frequencySort(string s) {
        int mapp[123] = {0};

        for (char x : s)
        {
            mapp[x]++;
        }

        priority_queue<pair<int, char> > q;

        for (int i = 0; i < 123; i++)
        {
            if (mapp[i]) {
                q.push({mapp[i], i});
            }
        }

        s = "";

        while (!q.empty())
        {
            pair<int, char> curr = q.top();
            q.pop();

            for (int i = 0; i < curr.first; i++)
            {
                s += curr.second;
            }
        }

        return s;
    }
};
