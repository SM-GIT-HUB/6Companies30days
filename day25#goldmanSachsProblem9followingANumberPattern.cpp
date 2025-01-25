class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans = "";
        int n = S.size();
        
        int currMax = 0;
        int last = 0;
        int j = 0;
        
        for (int i = 0; i < n; i++)
        {
            int ds = 0;
            char x = S[i];
            
            j = i + 1;
            
            while (j < n && S[j] == 'D')
            {
                ds++;
                j++;
            }
            
            if (x == 'I')
            {
                if (i == 0)
                {
                    currMax = ds + 2;
                    last++;
                    
                    ans += (last + '0');
                    ans += (currMax + '0');
                    
                    last = currMax;
                }
                else
                {
                    currMax = currMax + ds + 1;
                    
                    last = currMax;
                    ans += (last + '0');
                }
                
                for (int k = 0; k < ds; k++)
                {
                    last--;
                    ans += (last + '0');
                    i++;
                }
            }
            else
            {
                if (i == 0)
                {
                    currMax = ds + 2;
                    
                    ans += (currMax + '0');
                    ans += (currMax - 1 + '0');
                    
                    last = currMax - 1;
                }
                else
                {
                    ans += (last - 1 + '0');
                    last--;
                }
            }
        }
        
        return ans;
    }
};
