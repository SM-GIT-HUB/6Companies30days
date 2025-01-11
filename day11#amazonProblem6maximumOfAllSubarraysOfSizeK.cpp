class Solution {
  public:
    class comp {
    public:
        bool operator()(int a, int b)
        {
            return (a < b);
        }
    };
  
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> ans;
        int n = arr.size();
        
        unordered_map<int, int> mapp;
        priority_queue<int, vector<int>, comp> q;
        
        for (int i = 0; i < k; i++)
        {
            q.push(arr[i]);
            mapp[arr[i]]++;
        }
        
        ans.push_back(q.top());
        
        for (int i = 1; i + k - 1 < n; i++)
        {
            mapp[arr[i - 1]]--;
            mapp[arr[i + k - 1]]++;
            
            q.push(arr[i + k - 1]);
            
            while (mapp[q.top()] == 0)
            {
                q.pop();
            }
            
            ans.push_back(q.top());
        }
        
        return ans;
    }
};
