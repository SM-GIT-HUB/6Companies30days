class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size();

        vector<long long> mapp(100002);
        long long ans = 0;

        long long runSum = 0;

        long long start = 0, end = 0;

        while (end < n)
        {
            if (mapp[nums[end]])
            {
                while (mapp[nums[end]])
                {
                    runSum -= nums[start];
                    mapp[nums[start++]]--;
                }
                
                runSum += nums[end];
                mapp[nums[end]] = 1;

                while (end - start + 1 > k)
                {
                    mapp[nums[start]]--;
                    runSum -= nums[start++];
                }
                
                if (end - start + 1 == k) {
                    ans = max(runSum, ans);
                }
            }
            else
            {
                runSum += nums[end];
                mapp[nums[end]] = 1;

                while (end - start + 1 > k)
                {
                    mapp[nums[start]]--;
                    runSum -= nums[start++];
                }

                if (end - start + 1 == k) {
                    ans = max(runSum, ans);
                }
            }

            end++;
        }

        return ans;
    }
};
