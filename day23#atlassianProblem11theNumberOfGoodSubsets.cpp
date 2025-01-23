class Solution {
public:
    int mod = 1e9 + 7;
    int bitMask[31] = {0};
    int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    void getBitMasks()
    {
        for (int num = 1; num <= 30; num++)
        {
            int n = num;
            bool valid = true;

            int mask = 0;

            for (int i = 0; i < 10; i++)
            {
                if (n % primes[i] == 0)
                {
                    if (n / primes[i] % primes[i] == 0)
                    {
                        valid = false;
                        break;
                    }

                    mask = mask | (1 << i);
                    n = n / primes[i];
                }
            }

            if (valid) {
                bitMask[num] = mask;
            }
        }
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        int n = nums.size();
        int count[31] = {0};

        for (int x : nums)
        {
            count[x]++;
        }

        getBitMasks();

        long long dp[1 << 10] = {0};
        dp[0] = 1;

        for (int num = 2; num <= 30; num++)
        {
            if (count[num] > 0 && bitMask[num])
            {
                int mask = bitMask[num];

                for (int state = (1 << 10) - 1; state >= 0; state--)
                {
                    if ((state & mask) == 0) {
                        dp[state | mask] = (dp[state | mask] + dp[state] * count[num]) % mod;
                    }
                }
            }
        }

        long long result = 0;

        for (int state = 1; state < (1 << 10); state++)
        {
            result = (result + dp[state]) % mod;
        }

        for (int i = 0; i < count[1]; i++)
        {
            result = (result * 2) % mod;
        }

        return result;
    }
};
