class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int start = 0, end = 0;
        int count = 0;
        int ans = 0;

        while (end < n)
        {
            count += (nums[end] & 1)? 1 : 0;

            if (count == k)
            {
                int c1 = 0;

                while (start <= end && !(nums[start] & 1))
                {
                    c1++;
                    start++;
                }

                int c2 = 0;

                end++;

                while (end < n && !(nums[end] & 1))
                {
                    c2++;
                    end++;
                }

                ans += (c1 + 1) * (c2 + 1);

                start++;
                count--;
            }
            else
                end++;
        }

        return ans;
    }
};
