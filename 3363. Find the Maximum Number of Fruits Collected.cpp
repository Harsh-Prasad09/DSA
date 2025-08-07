class Solution {
public:
    int solve1(int i, int j, vector<vector<int>> &fruits, int &n, vector<vector<int>> &dp) {
        if (j < i) return INT_MIN;
        if (i == n-1 && j == n-1) return fruits[n-1][n-1];

        if (dp[i][j] != -1) return dp[i][j];

        int op1 = fruits[i][j] + solve1(i+1, j, fruits, n, dp);
        int op2 = INT_MIN;
        if (j-1 < n) op2 = fruits[i][j] + solve1(i+1, j-1, fruits, n, dp);
        int op3 = INT_MIN; 
        if (j+1 < n) op3 = fruits[i][j] + solve1(i+1, j+1, fruits, n, dp);

        return dp[i][j] = max({op1, op2, op3});
    }

    int solve2(int i, int j, vector<vector<int>> &fruits, int &n, vector<vector<int>> &dp) {
        if (j > i) return INT_MIN;
        if (i == n-1 && j == n-1) return fruits[n-1][n-1];

        if (dp[i][j] != -1) return dp[i][j];

        int op1 = fruits[i][j] + solve2(i, j+1, fruits, n, dp);
        int op2 = INT_MIN;
        if (i-1 < n) op2 = fruits[i][j] + solve2(i-1, j+1, fruits, n, dp);
        int op3 = INT_MIN; 
        if (i+1 < n) op3 = fruits[i][j] + solve2(i+1, j+1, fruits, n, dp);

        return dp[i][j] = max({op1, op2, op3});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        int ans = 0;
        for (int i = 0; i<n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }

        vector<vector<int>> dp1(n+1, vector<int>(n+1, -1)); 
        vector<vector<int>> dp2(n+1, vector<int>(n+1, -1)); 
        ans += solve1(0, n-1, fruits, n, dp1) + solve2(n-1, 0, fruits, n, dp2);

        return ans;
    }
};
