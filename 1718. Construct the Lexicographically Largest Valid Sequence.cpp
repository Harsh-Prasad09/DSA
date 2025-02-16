class Solution {
public:
    bool solve(int idx, int n, vector<int> &ans, vector<int> &vis) {
        if (idx >= ans.size()) return true;
        if (ans[idx] != -1) return solve(idx+1, n, ans, vis);

        for (int num = n; num>=1; num--) {
            if (vis[num]) continue;

            vis[num] = 1;
            ans[idx] = num;

            if (num == 1) {
                if (solve(idx+1, n, ans, vis)) return true;
            }
            else {
                int i = ans[idx] + idx;
                if (i < ans.size() && ans[i] == -1) {
                    ans[i] = num;
                    if (solve(idx+1, n, ans, vis)) return true;
                    ans[i] = -1;
                }
            }

            vis[num] = 0;
            ans[idx] = -1;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1, -1);
        vector<int> vis(n+1, 0);
        
        solve(0, n, ans, vis);

        return ans;
    }
};
