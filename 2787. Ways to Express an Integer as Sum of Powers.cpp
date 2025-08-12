class Solution {
public:
    vector<long long> powers;
    const int mod = 1e9 + 7;

    int solve(int n, int j, int &len, vector<vector<int>> &dp) {
        if (n == 0) return 1;
        if (n < 0 || j >= len) return 0;

        if (dp[n][j] != -1) return dp[n][j];

        int take = solve(n - powers[j], j + 1, len, dp);
        int nottake = solve(n, j + 1, len, dp);

        return dp[n][j] = (take + nottake) % mod;
    }

    long long intPower(int base, int exp) {
        long long result = 1;
        while (exp--) result *= base;
        return result;
    }

    int numberOfWays(int n, int x) {
        for (int i = 1; ; i++) {
            long long exp = intPower(i, x);
            if (exp > n) break;
            powers.push_back(exp);
        }
        int len = powers.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(len + 1, -1));
        return solve(n, 0, len, dp);
    }
};
