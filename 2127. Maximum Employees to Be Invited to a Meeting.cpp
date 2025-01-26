class Solution {
public:
    int bfs(int start, unordered_map<int, vector<int>> &adj, vector<bool> &vis) {
        queue<pair<int, int>> qu;
        qu.push({start, 0});
        int maxi = 0;

        while (!qu.empty()) {
            auto it = qu.front();
            qu.pop();

            int node = it.first;
            int dist = it.second;

            for (auto &nbr: adj[node]) {
                if (!vis[nbr]) {
                    vis[nbr] = true;
                    qu.push({nbr, dist+1});
                    maxi = max(maxi, dist+1);
                }
            }
        }

        return maxi;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i<n; i++) {
            adj[favorite[i]].push_back(i);
        }

        int maxCycleCnt = 0;
        int cnt = 0;

        vector<bool> vis(n, false);

        for (int i = 0; i<n; i++) {
            if (!vis[i]) {
                unordered_map<int, int> mpp;

                int curr = i;
                int currCnt = 0;

                while(!vis[curr]) {
                    vis[curr] = true;
                    mpp[curr] = currCnt;

                    int next = favorite[curr];
                    currCnt++;

                    if (mpp.count(next)) {
                        int len = currCnt - mpp[next];
                        maxCycleCnt = max(maxCycleCnt, len);

                        if (len == 2) {
                            vector<bool> visNode(n, false);
                            visNode[curr] = true;
                            visNode[next] = true;
                            cnt += 2 + bfs(curr, adj, visNode) + bfs(next, adj, visNode);
                        }
                        break;
                    }
                    curr = next;
                }
            }
        }

        return max(cnt, maxCycleCnt);
    }
};
