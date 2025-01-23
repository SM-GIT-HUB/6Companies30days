class Solution {
public:
    int binSearch(int elem, int n, vector<int>& arr)
    {
        int start = 0, end = n - 1;
        int mid = 0;
        int closest = arr[0];

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (abs(arr[mid] - elem) < abs(closest - elem) || (abs(arr[mid] - elem) == abs(closest - elem) && arr[mid] < closest)) {
                closest = arr[mid];
            }

            if (arr[mid] < elem) {
                start = mid + 1;
            }
            else
                end = mid - 1;
        }

        return closest;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        int n = arr2.size();

        sort(arr2.begin(), arr2.end());
        int elem = 0;

        for (int x : arr1)
        {
            elem = binSearch(x, n, arr2);

            if (abs(x - elem) > d) {
                count++;
            }
        }

        return count;
    }
};
