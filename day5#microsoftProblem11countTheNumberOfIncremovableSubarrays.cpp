class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();

        vector<bool> prefix(n, false);

        prefix[0] = true;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1]) {
                break;
            }

            prefix[i] = true;
        }

        vector<bool> suffix(n, false);

        suffix[n - 1] = true;

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] >= nums[i + 1]) {
                break;
            }

            suffix[i] = true;
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                bool left = (i == 0) || prefix[i - 1];
                bool right = (j == n - 1) || suffix[j + 1];
                bool boundary = (i == 0 || j == n - 1 || nums[i - 1] < nums[j + 1]);

                ans += (left && right && boundary);
            }
        }

        return ans;
    }
};
