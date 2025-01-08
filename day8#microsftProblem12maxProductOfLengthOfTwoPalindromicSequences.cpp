class Solution {
public:
    void generateAll(int index, int n, int mask, string output, string &s, vector<string>& subs, vector<int>& masks)
    {
        if (index >= n)
        {
            if (output.size())
            {
                subs.push_back(output);
                masks.push_back(mask);
            }

            return;
        }

        generateAll(index + 1, n, mask | (1 << index), output + s[index], s, subs, masks);
        generateAll(index + 1, n, mask, output, s, subs, masks);
    }

    bool isPalin(string &x)
    {
        int start = 0, end = x.size() - 1;

        while (start < end)
        {
            if (x[start++] != x[end--]) {
                return false;
            }
        }

        return true;
    }

    vector<int> getPalinMasks(vector<string>& subs, vector<int>& masks, int n)
    {
        vector<int> newMasks;

        for (int i = 0; i < n; i++)
        {
            if (isPalin(subs[i])) {
                newMasks.push_back(masks[i]);
            }
        }

        return newMasks;
    }

    bool isDisjoint(int maskA, int maskB)
    {
        return (maskA & maskB) == 0;
    }

    int maxProduct(string s) {
        vector<string> subs;
        vector<int> masks;
        
        generateAll(0, s.size(), 0, "", s, subs, masks);

        masks = getPalinMasks(subs, masks, subs.size());

        int ans = 0;

        for (int i = 0; i < masks.size(); i++)
        {
            for (int j = i + 1; j < masks.size(); j++)
            {
                if (isDisjoint(masks[i], masks[j]))
                {
                    int prod = __builtin_popcount(masks[i]) * __builtin_popcount(masks[j]);
                    ans = max(prod, ans);
                }
            }
        }

        return ans;
    }
};
