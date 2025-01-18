class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > q;

        for (auto &x : nums)
        {
            q.push(x);
        }

        for (int i = 0; i < k; i++)
        {
            int top = q.top();
            q.pop();

            top++;
            q.push(top);
        }

        long long ans = 1;
        int mod = 1e9 + 7;

        while (!q.empty())
        {
            ans *= q.top();
            q.pop();

            ans = ans % mod;
        }

        return ans;
    }
};
