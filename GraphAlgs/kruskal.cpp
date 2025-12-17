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
        auto comp = [](auto& e1, auto& e2) {
            return e1[2] < e2[2];
        };
        sort(edges.begin(), edges.end(), comp);
        
        DSU dsu(V);
        int minCost = 0;
        
        for (const auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            minCost += (dsu.Union(u, v) == true) ?  w : 0; 
        }
        return minCost;
    }
};
