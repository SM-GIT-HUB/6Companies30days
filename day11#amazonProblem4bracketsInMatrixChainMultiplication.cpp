class Solution {
  public:
    pair<int, string> recur(int i, int j, vector<int>& arr)
    {
        if (i + 1 == j)
        {
            char mat = 'A' + i;
            return {0, string(1, mat)};
        }
        
        pair<int, string> ans = {INT_MAX, ""};
        
        for (int k = i + 1; k < j; k++)
        {
            pair<int, string> one = recur(i, k, arr);
            pair<int, string> two = recur(k, j, arr);
            
            int val = one.first + two.first + arr[i] * arr[k] * arr[j];
            string mul = "(" + one.second + two.second + ")";
            
            pair<int, string> curr = {val, mul};
            
            ans = (ans.first < curr.first)? ans : curr;
        }
        
        return ans;
    }
    
    
    pair<int, string> memoization(int i, int j, vector<int>& arr, vector<vector<pair<int, string> > >& dp)
    {
        if (i + 1 == j)
        {
            char mat = 'A' + i;
            return {0, string(1, mat)};
        }
        
        if (dp[i][j].first != -1) {
            return dp[i][j];
        }
        
        pair<int, string> ans = {INT_MAX, ""};
        
        for (int k = i + 1; k < j; k++)
        {
            pair<int, string> one = memoization(i, k, arr, dp);
            pair<int, string> two = memoization(k, j, arr, dp);
            
            int val = one.first + two.first + arr[i] * arr[k] * arr[j];
            string mul = "(" + one.second + two.second + ")";
            
            pair<int, string> curr = {val, mul};
            
            ans = (ans.first < curr.first)? ans : curr;
        }
        
        return dp[i][j] = ans;
    }
    
    
    pair<int, string> tabulation(int n, vector<int>& arr)
    {
        vector<vector<pair<int, string> > > dp(n + 1, vector<pair<int, string> >(n + 1, {-1, ""}));
        
        for (int i = n - 2; i >= 0; i--)
        {
            char mat = 'A' + i;
            dp[i][i + 1] = {0, string(1, mat)};
            
            for (int j = i + 2; j < n; j++)
            {
                pair<int, string> ans = {INT_MAX, ""};
                
                for (int k = i + 1; k < j; k++)
                {
                    pair<int, string> one = dp[i][k];
                    pair<int, string> two = dp[k][j];
                    
                    int val = one.first + two.first + arr[i] * arr[k] * arr[j];
                    string mul = "(" + one.second + two.second + ")";
                    
                    pair<int, string> curr = {val, mul};
                    
                    ans = (ans.first < curr.first)? ans : curr;
                }
                
                dp[i][j] = ans;
            }
        }
        
        return dp[0][n - 1];
    }
  
  
    string matrixChainOrder(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        // pair<int, string> ans = recur(0, n - 1, arr);
        
        // vector<vector<pair<int, string> > > dp(n, vector<pair<int, string> >(n, {-1, ""}));
        
        // pair<int, string> ans = memoization(0, n - 1, arr, dp);
        
        pair<int, string> ans = tabulation(n, arr);
        
        return ans.second;
    }
};
