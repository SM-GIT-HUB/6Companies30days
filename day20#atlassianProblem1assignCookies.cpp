class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), [](int a, int b) {
            return (a > b);
        });
        
        sort(s.begin(), s.end(), [](int a, int b) {
            return (a > b);
        });
        
        int gn = g.size();
        int sn = s.size();

        int gi = 0, si = 0;
        int ans = 0;

        while (gi < gn && si < sn)
        {
            if (g[gi] <= s[si])
            {
                ans++;
                gi++;
                si++;
            }
            else
                gi++;
        }

        return ans;
    }
};
