class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mapp(26, 0);

        for (char x : s)
        {
            mapp[x - 'a']++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (mapp[s[i] - 'a'] < 2) {
                return i;
            }
        }

        return -1;
    }
};
