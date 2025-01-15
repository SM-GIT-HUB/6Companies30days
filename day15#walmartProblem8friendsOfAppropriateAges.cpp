class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int ans = 0;

        sort(ages.begin(), ages.end(), [](int a, int b) {
            return (a > b);
        });

        int index = 0;

        while (index < n)
        {
            int x = ages[index];

            int end = n - 1;

            while (end > index)
            {
                if ( !(ages[end] <= 0.5 * x + 7) ) {
                    break;
                }

                end--;
            }

            int req = end - index;
            ans += req;

            index++;

            while (index < n && ages[index] == ages[index - 1])
            {
                ans += req;
                index++;
            }
        }

        return ans;
    }
};
