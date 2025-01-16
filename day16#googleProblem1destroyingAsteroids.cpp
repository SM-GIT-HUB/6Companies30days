class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = mass;
        sort(asteroids.begin(), asteroids.end());

        for (int x : asteroids)
        {
            if (x > m) {
                return false;
            }

            m += x;
        }

        return true;
    }
};
