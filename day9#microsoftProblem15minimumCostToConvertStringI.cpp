class Solution {
public:
    void getAdj(unordered_map<char, vector<pair<char, int> > >& adj, vector<char>& original, vector<char>& changed, vector<int>& cost)
    {
        int n = cost.size();

        for (int i = 0; i < n; i++)
        {
            adj[original[i]].push_back({changed[i], cost[i]});
        }
    }

    long long getDistance(int node, int tar, unordered_map<char, vector<pair<char, int> > >& adj)
    {
        unordered_map<char, long long> dist;
        dist[node] = 0;

        set<pair<long long, char> > sett;
        sett.insert({0, node});

        while (!sett.empty())
        {
            pair<long long, char> top = *sett.begin();
            sett.erase(top);
            
            int u = top.second;

            if (u == tar) {
                return dist[tar];
            }

            for (auto x : adj[u])
            {
                char v = x.first;
                long long w = x.second;
                
                if (dist.find(v) == dist.end() || dist[u] + w < dist[v])
                {
                    sett.erase({dist[v], v});
                    dist[v] = dist[u] + w;
                    
                    sett.insert({dist[v], v});
                }
            }
        }

        if (dist.find(tar) == dist.end()) {
            return -1;
        }
        else
            return dist[tar];
    }

    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int> > > adj;
        getAdj(adj, original, changed, cost);

        int n = source.size();

        unordered_map<pair<char, char>, long long, pair_hash> mapp;

        long long totalCost = 0;

        for (int i = 0; i < n; i++)
        {
            if (source[i] == target[i]) {
                continue;
            }

            pair<char, char> key = {source[i], target[i]};

            if (mapp.find(key) != mapp.end())
            {
                totalCost += mapp[key];
                continue;
            }

            long long dist = getDistance(source[i], target[i], adj);

            if (dist == -1) {
                return -1;
            }

            mapp[key] = dist;

            totalCost += dist;
        }

        return totalCost;
    }
};
