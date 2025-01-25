class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        long long sum = 0, eSum = 0;
        long long sqSum = 0, esqSum = 0;
        
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            eSum += (i + 1);
            
            sqSum += (long long)arr[i] * arr[i];
            esqSum += (long long)(i + 1) * (i + 1);
        }
        
        long long xmiy = sum - eSum;
        long long xsqy = sqSum - esqSum;
        
        long long xpy = xsqy / xmiy;
        
        long long x = (xpy + xmiy) / 2;
        long long y = xpy - x;
        
        return {(int)x, (int)y};
    }
};
