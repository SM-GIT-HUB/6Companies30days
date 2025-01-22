class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int ans = 0;

        unordered_set<int> startMasks;

        for (const auto& word : startWords)
        {
            int mask = 0;
            for (char c : word)
            {
                mask |= (1 << (c - 'a'));
            }

            startMasks.insert(mask);
        }

        for (auto x : targetWords)
        {
            int mask = 0;

            for (char c : x)
            {
                mask = mask | (1 << (c - 'a') );
            }

            for (char c : x)
            {
                int modifiedMask = mask & ~(1 << (c - 'a'));

                if (startMasks.count(modifiedMask))
                {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};
