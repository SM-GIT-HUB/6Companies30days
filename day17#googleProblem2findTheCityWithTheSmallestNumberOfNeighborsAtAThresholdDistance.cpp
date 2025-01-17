class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int> > dist(n, vector<int>(n, INT_MAX));

        for (int u = 0; u < n; u++)
        {
            dist[u][u] = 0;
        }

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int k = 0; k < n; k++)
        {
            for (int u = 0; u < n; u++)
            {
                for (int v = 0; v < n; v++)
                {
                    if (dist[u][k] != INT_MAX && dist[k][v] != INT_MAX)
                    {
                        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }
        }

        int city = -1;
        int minCities = INT_MAX;

        for (int u = 0; u < n; u++)
        {
            int cities = 0;

            for (int v = 0; v < n; v++)
            {
                if (dist[u][v] <= distanceThreshold) {
                    cities++;
                }
            }

            if (cities <= minCities)
            {
                city = u;
                minCities = cities;
            }
        }

        return city;
    }
};
