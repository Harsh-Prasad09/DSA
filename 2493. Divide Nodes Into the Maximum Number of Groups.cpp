class Solution {
public:
    bool isBipartite(unordered_map<int, vector<int>> &adj, int curr, vector<int>& colors, int currColor) {
        colors[curr] = currColor;

        for(int &nbr : adj[curr]) {
            if(colors[nbr] == colors[curr]) {
                return false;
            }

            if(colors[nbr] == -1) {
                if(isBipartite(adj, nbr, colors, 1 - currColor) == false) {
                    return false;
                }
            }
        }

        return true;
    }

    int bfs(unordered_map<int, vector<int>> &adj, int currNode, int n) {
        queue<int> qu;
        vector<bool> vis(n, false);
        qu.push(currNode);
        vis[currNode] = true;

        int level = 1; 
        while(!qu.empty()) {

            int size = qu.size();
            while(size--) {
                int curr = qu.front();
                qu.pop();

                for(int &nbr : adj[curr]) {
                    if(vis[nbr])
                        continue;
                    
                    qu.push(nbr);
                    vis[nbr] = true;
                }
            }
            level++;
        }

        return level-1;
    }

    int getMaxi(unordered_map<int, vector<int>> &adj, int curr, vector<bool>& vis, vector<int>& levels) {
        int maxGrp = levels[curr];
        vis[curr] = true;

        for(int &nbr : adj[curr]) {
            if(!vis[nbr]) {
                maxGrp = max(maxGrp, getMaxi(adj, nbr, vis, levels));
            }
        }

        return maxGrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj; 

        for(auto& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(n, -1); 
        for(int node = 0; node < n; node++) { 
            if(colors[node] == -1) {
                if(isBipartite(adj, node, colors, 1) == false) return -1;
            }
        }

        vector<int> levels(n, 0);
        for(int i = 0; i < n; i++) { 
            levels[i] = bfs(adj, i, n); 
        }


        int maxi = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) { 
            if(!vis[i]) maxi += getMaxi(adj, i, vis, levels);
        }

        return maxi;
    }
};
