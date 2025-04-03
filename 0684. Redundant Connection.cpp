class DisjointSet{
private:
    vector<int> parent, size, rank;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        for (int i = 0; i<=n; i++) parent[i] = i;
    }

    int findUltimateParent(int node){
        if (parent[node] == node) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void UnionBySize(int u, int v){
        int ultimateParent_u = findUltimateParent(u);
        int ultimateParent_v = findUltimateParent(v);

        if (ultimateParent_u == ultimateParent_v) return; 

        if (size[ultimateParent_u] < size[ultimateParent_v]){
            parent[ultimateParent_u] = ultimateParent_v;
            size[ultimateParent_v] += size[ultimateParent_u];
        }
        else{
            parent[ultimateParent_v] = ultimateParent_u;
            size[ultimateParent_u] += size[ultimateParent_v];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n+1);

        for (auto it: edges) {
            int a = it[0], b = it[1];
            int parent_a = ds.findUltimateParent(a);
            int parent_b = ds.findUltimateParent(b);

            if (parent_a == parent_b) return it;
            ds.UnionBySize(a, b);
        }

        return {};
    }
};
