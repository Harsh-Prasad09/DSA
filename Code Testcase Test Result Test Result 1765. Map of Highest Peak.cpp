class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        vector<vector<int>> heights(n, vector<int>(m, -1));

        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                if (isWater[i][j] == 1) {
                    heights[i][j] = 0;
                    pq.push({0, i, j});
                } 
            }
        }

        while (!pq.empty()) {
            auto idx = pq.top();
            pq.pop();
            int val = idx[0];
            int x = idx[1];
            int y = idx[2];

            if (x-1 >= 0 && heights[x-1][y] == -1) {
                heights[x-1][y] = val+1;
                pq.push({val+1, x-1, y});
            }
            if (x+1 < n && heights[x+1][y] == -1) {
                heights[x+1][y] = val+1;
                pq.push({val+1, x+1, y});
            }
            if (y-1 >= 0 && heights[x][y-1] == -1) {
                heights[x][y-1] = val+1;
                pq.push({val+1, x, y-1});
            }
            if (y+1 < m && heights[x][y+1] == -1) {
                heights[x][y+1] = val+1;
                pq.push({val+1, x, y+1});
            }
        }

        return heights;
    }
};
