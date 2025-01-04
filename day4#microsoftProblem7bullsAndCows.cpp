class Solution {
public:
    string getHint(string secret, string guess) {
        string ans = "";

        int n = secret.size();
        int bulls = 0, cows = 0;
        // unordered_map<char, int> mapp;
        vector<int> mapp(10, 0);

        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            else
            {
                if (mapp[secret[i] - '0']++ < 0) {
                    cows++;
                }

                if (mapp[guess[i] - '0']-- > 0) {
                    cows++;
                }
            }
        }

        ans = to_string(bulls) + "A" + to_string(cows) + "B";
        
        return ans;
    }
};
