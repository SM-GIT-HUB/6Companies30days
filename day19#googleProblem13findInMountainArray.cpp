/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int getPivotIndex(int n, MountainArray &mArr)
    {
        int start = 0, end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (mArr.get(mid) < mArr.get(mid + 1)) {
                start = mid + 1;
            }
            else
                end = mid - 1;
        }

        return start;
    }

    int binSearch(int start, int end, int target, MountainArray &mArr, int one)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            int val = mArr.get(mid);

            if (val == target) {
                return mid;
            }
            else if (one == 1)
            {
                if (target > val) {
                    start = mid + 1;
                }
                else
                    end = mid - 1;
            }
            else
            {
                if (target > val) {
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int pivot = getPivotIndex(n, mountainArr);

        int index = binSearch(0, pivot, target, mountainArr, 1);

        if (index != -1) {
            return index;
        }

        index = binSearch(pivot + 1, n - 1, target, mountainArr, -1);

        return index;
    }
};
