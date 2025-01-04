class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long median = nums[nums.size() / 2];
        long long ans = 0;

        for (long long x : nums)
        {
            ans += abs(x - median);
        }

        return ans;
    }
};
