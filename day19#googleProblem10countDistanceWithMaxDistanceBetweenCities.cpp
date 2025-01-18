class Solution {
public:
    int dfs(int u, int parent, int x, int y, vector<vector<int> >& dist, bool *visited, vector<vector<int> >& adj)
    {
        if (dist[u][x] > dist[x][y] || dist[u][y] > dist[x][y]) {
            return 1;
        }

        if ( (dist[u][x] == dist[x][y] && u < y) || (dist[u][y] == dist[x][y] && u < x) ) {
            return 1;
        }

        int res = 1;
        visited[u] = true;

        for (int v : adj[u])
        {
            if (!visited[v] && v != parent) {
                res *= dfs(v, u, x, y, dist, visited, adj);
            }
        }

        if (dist[u][x] + dist[u][y] > dist[x][y]) {
            res++;
        }

        return res;
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int> > adj(n + 1);
        vector<vector<int> > dist(n + 1, vector<int>(n + 1, INT_MAX));

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            dist[u][v] = dist[v][u] = 1;
        }

        for (int u = 1; u <= n; u++)
        {
            dist[u][u] = 0;
        }

        for (int k = 1; k <= n; k++)
        {
            for (int u = 1; u <= n; u++)
            {
                for (int v = 1; v <= n; v++)
                {
                    if (dist[u][k] != INT_MAX && dist[k][v] != INT_MAX) {
                        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }
        }

        vector<int> ans(n - 1, 0);

        for (int u = 1; u < n; u++)
        {
            for (int v = u + 1; v <= n; v++)
            {
                bool visited[17] = {false};
                ans[dist[u][v] - 1] += dfs(u, -1, u, v, dist, visited, adj);
            }
        }

        return ans;
    }
};
