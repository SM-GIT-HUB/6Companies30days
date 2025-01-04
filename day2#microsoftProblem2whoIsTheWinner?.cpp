class Solution {
public:
    int recur(int n, int k)
    {
        if (n == 1) {
            return 1;
        }

        int ans = ( recur(n - 1, k) + (k - 1) ) % n + 1;

        return ans;
    }

    int findTheWinner(int n, int k) {
        if (n == 1) {
            return 1;
        }

        // int ans = recur(n, k);

        int ans = 1;

        for (int i = 2; i <= n; i++)
        {
            ans = (ans + k - 1) % i + 1;
        }

        return ans;
    }
};
