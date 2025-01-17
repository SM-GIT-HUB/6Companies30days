class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int> > values;

        for (int i = 0; i < n; i++)
        {
            values.push_back({aliceValues[i], bobValues[i]});
        }

        sort(values.begin(), values.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return ( (a.first + a.second) > (b.first + b.second) );
        });

        int aVal = 0;
        int bVal = 0;

        for (int i = 0; i < n; i++)
        {
            if (!(i & 1)) {
                aVal += values[i].first;
            }
            else
                bVal += values[i].second;
        }

        if (aVal > bVal) {
            return 1;
        }
        else if (bVal > aVal) {
            return -1;
        }

        return 0;
    }
};
