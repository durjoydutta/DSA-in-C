class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, -1);
        vector<vector<pair<int, int>>> adj(V);
        for (const auto& it: edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0}); // {wt, u}
        int minW = 0;
        
        while (!pq.empty()) {
            auto [wt, u] = pq.top(); pq.pop();
            if (vis[u] != -1) continue;
            vis[u] = 1;
            minW += wt;
            for (const auto&[v, w]: adj[u]) {
                pq.push({w, v});
            }
        }
        
        return minW;
    }
};
