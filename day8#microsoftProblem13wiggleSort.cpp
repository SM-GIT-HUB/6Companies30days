class Solution {
public:
    int virtualIndex(int i, int n)
    {
        return (1 + 2 * i) % (n | 1);
    }

    void dutchFlag(int n, vector<int>& arr, int x)
    {
        int i = 0, j = 0, k = n - 1;

        while (j <= k)
        {
            if (arr[virtualIndex(j, n)] > x) {
                swap(arr[virtualIndex(j++, n)], arr[virtualIndex(i++, n)]);
            }
            else if (arr[virtualIndex(j, n)] < x) {
                swap(arr[virtualIndex(j, n)], arr[virtualIndex(k--, n)]);
                k--;
            }
            else
                j++;
        }
    }

    int findMedian(vector<int>& nums)
    {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + (n / 2), nums.end());

        return nums[n / 2];
    }

    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) {
            return;
        }

        int median = findMedian(nums);

        dutchFlag(n, nums, median);
    }
};
