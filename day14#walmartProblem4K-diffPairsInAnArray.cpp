class Solution {
public:
    int biSearch(int start, int end, int val, vector<int>& nums)
    {
        int mid = 0;

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (val == nums[mid]) {
                return mid;
            }
            else if (val > nums[mid]) {
                start = mid + 1;
            }
            else
                end = mid - 1;
        }

        return -1;
    }

    int nextIndex(int index, int n, vector<int>& nums)
    {
        int i = index + 1;

        while (i < n && nums[i] == nums[index])
        {
            i++;
        }

        return i;
    }

    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        int val = 0;
        int in = 0;
        
        for (int i = 0; i < n - 1; i = nextIndex(i, n, nums))
        {
            val = k + nums[i];

            in = biSearch(i + 1, n - 1, val, nums);

            if (in == -1) {
                continue;
            }
            else
                ans++;
        }

        return ans;
    }
};
