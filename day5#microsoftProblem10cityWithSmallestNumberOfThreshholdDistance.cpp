class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i)
        {
            dist[i][i] = 0;
        }

        for (const auto& edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int minCity = -1;
        int minCount = n + 1;

        for (int i = 0; i < n; ++i)
        {
            int reachableCities = 0;
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][j] <= distanceThreshold) {
                    reachableCities++;
                }
            }

            if (reachableCities <= minCount)
            {
                minCount = reachableCities;
                minCity = i;
            }
        }

        return minCity;
    }
};
