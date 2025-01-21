class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long mini = LONG_LONG_MAX;
        long long leftSum = accumulate(grid[0].begin(), grid[0].end(), 0ll);
        long long rightSum = 0ll;

        for (int i = 0; i<n; i++) {
            leftSum -= 1ll*grid[0][i];
            if (i != 0) rightSum += (1ll*grid[1][i-1]);

            mini = min(mini, max(leftSum, rightSum));
        }

        return mini;
    }
};
