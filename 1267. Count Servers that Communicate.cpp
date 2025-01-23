class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                if (grid[i][j] == 1) {
                    int sum = accumulate(grid[i].begin(), grid[i].end(), 0);
                    if (sum > 1) cnt++;
                    else {
                        int c = 0;
                        for (int k = 0; k<n; k++) {
                            if (grid[k][j] == 1) {
                                c++;
                            }
                        }

                        if (c > 1) cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};
