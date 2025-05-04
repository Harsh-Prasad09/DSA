class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> count(100, 0);
        for (auto &domino: dominoes) {
            int u = min(domino[0], domino[1]);
            int v = max(domino[0], domino[1]);
            count[u*10+v]++;
        }

        int ans = 0;
        for (int i = 0; i<100; i++) {
            int cnt = count[i];
            if (cnt > 1) ans += (cnt*(cnt-1))/2;
        }

        return ans;
    }
};
