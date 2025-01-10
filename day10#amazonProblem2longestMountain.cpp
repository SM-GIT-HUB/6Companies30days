class Solution {
public:
    int getLen(int index, int n, vector<int>& arr)
    {
        int start = index - 1;

        while (start >= 0 && arr[start] < arr[start + 1])
        {
            start--;
        }

        int end = index + 1;

        while (end < n && arr[end] < arr[end - 1])
        {
            end++;
        }

        return (end - start - 1);
    }

    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        int ans = 0;

        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
            {
                ans = max(getLen(i, n, arr), ans);
            }
        }

        return ans;
    }
};
