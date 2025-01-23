class Solution {
public:
    int countCollisions(string directions) {
        int count = 0;
        int n = directions.size();

        int i = 0;

        while (i < n && directions[i] == 'L')
        {
            i++;
        }

        int j = n - 1;

        while (j >= 0 && directions[j] == 'R')
        {
            j--;
        }

        for (int index = i; index <= j; index++)
        {
            if (directions[index] != 'S') {
                count++;
            }
        }

        return count;
    }
};
