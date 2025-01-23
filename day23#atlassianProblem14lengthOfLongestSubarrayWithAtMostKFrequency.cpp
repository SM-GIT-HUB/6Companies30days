class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;

        int start = 0, end = 0, n = nums.size();
        int ans = 0;

        while (end < n)
        {
            mapp[nums[end]]++;

            while (mapp[nums[end]] > k)
            {
                mapp[nums[start++]]--;
            }

            ans = max(end - start + 1, ans);
            end++;
        }

        return ans;
    }
};
