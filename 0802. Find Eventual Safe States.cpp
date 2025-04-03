class Solution {
public:
    bool dfs(int idx, vector<vector<int>> &graph, unordered_map<int, bool> &mpp) {
        if (mpp.find(idx) != mpp.end()) return mpp[idx];

        mpp[idx] = false;
        for (int nbr: graph[idx]) {
            if (!dfs(nbr, graph, mpp)) return false;
        }
        mpp[idx] = true;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, bool> mpp;
        int n = graph.size();
        vector<int> ans;

        for (int i = 0; i<n; i++) {
            if (dfs(i, graph, mpp)) ans.push_back(i);
        }

        return ans;
    }
};
