class Solution {
public:
    int comb(int n, int k)
    {
        if (k < 0 || k > n) {
            return 0;
        }

        long ans = 1;

        for (int i = 0; i < k; i++) {
            ans = ans * (n - i) / (i + 1);
        }

        return ans;
    }

    int waysToReachStair(int k) {
        int ans = 0;

        for (int i = 0; i < 31; i++) {
            ans += comb(i + 1, (1 << i) - k);
        }
        
        return ans;
    }
};
