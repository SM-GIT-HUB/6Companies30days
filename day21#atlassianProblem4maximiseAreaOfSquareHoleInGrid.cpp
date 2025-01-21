class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hx = hBars[0];
        int hy = hBars[0];
        int hMaxi = 1;

        for (int i = 1; i < hBars.size(); i++)
        {
            if (hy + 1 == hBars[i]) {
                hy = hBars[i];
            }
            else
            {
                hMaxi = max(hy - hx + 2, hMaxi);
                hy = hx = hBars[i];
            }
        }

        hMaxi = max(hy - hx + 2, hMaxi);

        int vx = vBars[0];
        int vy = vBars[0];
        int vMaxi = 1;

        for (int i = 1; i < vBars.size(); i++)
        {
            if (vy + 1 == vBars[i]) {
                vy = vBars[i];
            }
            else
            {
                vMaxi = max(vy - vx + 2, vMaxi);
                vy = vx = vBars[i];
            }
        }

        vMaxi = max(vy - vx + 2, vMaxi);

        int diam = min(hMaxi, vMaxi);

        return (diam * diam);
    }
};
