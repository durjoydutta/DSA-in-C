class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    
    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    
    bool Union(int u, int v) {
        int parU = find(u), parV = find(v);
        if (parU == parV) return false;
        
        if (rank[parU] < rank[parV]) {
            parent[parU] = parV;
        } else if (rank[parV] < rank[parU]) {
            parent[parV] = parU;
        } else {
            parent[parV] = parU;
            rank[parU]++;
        }
        return true;
    }
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        DSU dsu(V);
        int components = V;
        int minCost = 0;
        
        while (components > 1) {
            vector<int> minEdge(V, -1);
            vector<int> minWt(V, INT_MAX);
            
            for (const auto e: edges) {
                int u = e[0], v = e[1], w = e[2];
                int parU = dsu.find(u), parV = dsu.find(v);
                if (parU == parV) continue;
                
                if (minEdge[parU] == -1 || w < minWt[parU]) {
                    minEdge[parU] = parV;
                    minWt[parU] = w;
                }
                if (minEdge[parV] == -1 || w < minWt[parV]) {
                    minEdge[parV] = parU;
                    minWt[parV] = w;
                }
            }
            
            for (int u = 0; u < V; ++u) {
                if (minEdge[u] == -1) continue;
                if (dsu.Union(u, minEdge[u])) {
                    minCost += minWt[u];
                    components--;
                }
            }
        }
        
        return minCost;
    }
};
