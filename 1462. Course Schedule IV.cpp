class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses, vector<int>(numCourses, 0));
        for (auto &it: prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[u][v] = 1;
        }

        for (int i = 0; i<numCourses; i++) {
            for (int u = 0; u<numCourses; u++) {
                for (int v = 0; v<numCourses; v++) {
                    adj[u][v] = adj[u][v] || (adj[u][i] && adj[i][v]);
                }
            }
        }

        vector<bool> ans;
        for (auto &it: queries) {
            int u = it[0];
            int v = it[1];
            ans.push_back(adj[u][v]);
        }

        return ans;
    }
};
