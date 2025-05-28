class Solution {
public:
    int bfs(int node, vector<vector<int>> &adj, int k) {
        int count = 0;
        queue<int> qu;
        qu.push(node);

        vector<bool> vis(adj.size(), false);
        vis[node] = true;
        while (!qu.empty() && k--) {
            int n = qu.size();
            count += n;
            for (int i = 0; i<n; i++) {
                int nd = qu.front();
                qu.pop();
                for (int adjNode: adj[nd]) {
                    if (!vis[adjNode]) {
                        vis[adjNode] = true;
                        qu.push(adjNode);
                    }
                }
            }
        }

        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        vector<vector<int>> adj1(n+1);
        for (vector<int> &edge: edges1) {
            int u = edge[0];
            int v = edge[1];

            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        int m = edges2.size();
        vector<vector<int>> adj2(m+1);
        for (vector<int> &edge: edges2) {
            int u = edge[0];
            int v = edge[1];

            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        vector<int> temp(m+1);
        int maxi = INT_MIN;
        for (int i = 0; i<=m; i++) {
            temp[i] = bfs(i, adj2, k);
            maxi = max(maxi, temp[i]);
        }

        vector<int> ans(n+1);
        for (int i = 0; i<=n; i++) {
            ans[i] = bfs(i, adj1, k+1) + maxi;
        }

        return ans;
    }
};
