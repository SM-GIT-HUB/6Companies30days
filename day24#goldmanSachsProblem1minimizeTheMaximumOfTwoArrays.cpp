class Solution {
public:
    long long gcd(long long a, long long b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    long long lcm(long long a, long long b)
    {
        return (a / gcd(a, b)) * b;
    }

    bool check(long long maxVal, long long div1, long long div2, long long cnt1, long long cnt2)
    {
        long long lcmVal = lcm(div1, div2);

        long long divBy1 = maxVal / div1;
        long long divBy2 = maxVal / div2;

        long long notDivBy1 = maxVal - divBy1;
        long long notDivBy2 = maxVal - divBy2;
        long long notDivTotal = maxVal - maxVal / lcmVal;

        return (notDivBy1 >= cnt1 && notDivBy2 >= cnt2 && notDivTotal >= (cnt1 + cnt2));
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long start = 1, end = 1e18;
        long long ans = -1;
        long long mid = 0;

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (check(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }

        return ans;
    }
};
