class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();

        if (n < 10) {
            return {};
        }

        vector<string> ans;

        unordered_map<string, int> mapp;
        string output = s.substr(0, 10);

        mapp[output] = 1;

        for (int i = 1; i + 9 < n; i++)
        {
            output.erase(0, 1);
            output += s[i + 9];

            if (mapp[output] == 1) {
                ans.push_back(output);
            }
            
            mapp[output]++;
        }

        return ans;
    }
};
