class Solution {
public:
    int recur(int index, int n, string &s, unordered_map<string, int>& mapp)
    {
        if (index >= n) {
            return 1;
        }
        
        string temp = "";
        
        for (int i = index; i < n; i++)
        {
            temp += s[i];
            
            int currAns = mapp[temp];
            int nextAns = 0;
            
            if (currAns) {
                nextAns = recur(i + 1, n, s, mapp);
            }
            
            if (currAns && nextAns) {
                return 1;
            }
        }
        
        return 0;
    }


    int memoization(int index, int n, string &s, unordered_map<string, int>& mapp, vector<int>& dp)
    {
        if (index >= n) {
            return 1;
        }

        if (dp[index] != -1) {
            return dp[index];
        }
        
        string temp = "";
        
        for (int i = index; i < n; i++)
        {
            temp += s[i];
            
            int currAns = mapp[temp];
            int nextAns = 0;
            
            if (currAns) {
                nextAns = memoization(i + 1, n, s, mapp, dp);
            }
            
            if (currAns && nextAns) {
                return dp[index] = 1;
            }
        }
        
        return dp[index] = 0;
    }


    int tabulation(int n, string &s, unordered_map<string, int>& mapp)
    {
        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for (int index = n - 1; index >= 0; index--)
        {
            string temp = "";
            
            for (int i = index; i < n; i++)
            {
                temp += s[i];
                
                int currAns = mapp[temp];
                int nextAns = 0;
                
                if (currAns) {
                    nextAns = dp[i + 1];
                }
                
                if (currAns && nextAns)
                {
                    dp[index] = 1;
                    break;
                }
            }
        }

        return dp[0];
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, int> mapp;
        
        for (string &x : wordDict)
        {
            mapp[x] = 1;
        }
        
        // int ans = recur(0, n, s, mapp);

        // vector<int> dp(n, -1);

        // int ans = memoization(0, n, s, mapp, dp);

        int ans = tabulation(n, s, mapp);
        
        return ans;
    }
};
