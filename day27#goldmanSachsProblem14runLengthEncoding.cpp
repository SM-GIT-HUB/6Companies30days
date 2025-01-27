class Solution {
  public:
    string encode(string s) {
        // code here
        string ans = "";
        
        int n = s.size();
        int index = 0;
        
        while (index < n)
        {
            int count = 0;
            char x = s[index];
            
            while (index < n && s[index] == x)
            {
                count++;
                index++;
            }
            
            ans += string(1, x) + to_string(count);
        }
        
        return ans;
    }
};
