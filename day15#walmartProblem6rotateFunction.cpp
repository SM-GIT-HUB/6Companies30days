class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int allSum = 0;

        for (int i = 0; i < n; i++)
        {
            allSum += nums[i];
            ans += (i * nums[i]);
        }

        int sumPrev = ans;

        int sumCurr = 0;
        
        for (int k = 1; k < n; k++)
        {
            sumCurr = sumPrev + allSum - n * nums[n - k];

            ans = max(sumCurr, ans);

            sumPrev = sumCurr;
        }

        return ans;
    }
};
