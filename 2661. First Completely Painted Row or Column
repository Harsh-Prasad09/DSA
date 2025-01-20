class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> mpp;
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                mpp[mat[i][j]] = {i, j};
            }
        }
        
        unordered_map<int, int> rows, cols;
        for (int i = 0; i<n*m; i++) {
            int x = mpp[arr[i]].first;
            int y = mpp[arr[i]].second;

            rows[x]++;
            cols[y]++;

            if (rows[x] == n || cols[y] == m) return i; 
        }

        return -1;
    }
};
