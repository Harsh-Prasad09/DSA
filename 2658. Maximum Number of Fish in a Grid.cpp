class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxi = 0;
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    int cnt = 0;
                    queue<pair<int, int>> qu;
                    qu.push({i, j});
                    while (!qu.empty()) {
                        auto [x, y] = qu.front();
                        qu.pop();
                        if (grid[x][y] > 0) {
                            cnt += grid[x][y];
                            grid[x][y] = 0; 

                            if (x > 0 && grid[x - 1][y] > 0) qu.push({x - 1, y});
                            if (x + 1 < n && grid[x + 1][y] > 0) qu.push({x + 1, y});
                            if (y > 0 && grid[x][y - 1] > 0) qu.push({x, y - 1});
                            if (y + 1 < m && grid[x][y + 1] > 0) qu.push({x, y + 1});
                        }
                    }
                    maxi = max(maxi, cnt);
                }
            }
        }
        return maxi;
    }
};
