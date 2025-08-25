typedef pair<int, pair<int, int>> P;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = mat.size(), m = mat[0].size();
        
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                pq.push({i+j, {i, j}});
            }
        }

        vector<int> ans;
        bool reversal = true;

        while (!pq.empty()) {
            int sum = pq.top().first;
            vector<int> temp;
            while (!pq.empty() && pq.top().first == sum) {
                int i = pq.top().second.first;
                int j = pq.top().second.second;
                temp.push_back(mat[i][j]);
                pq.pop();
            }

            if (reversal) {
                reverse(begin(temp), end(temp));
            }

            reversal = !reversal;
            ans.insert(ans.end(), temp.begin(), temp.end());
        }

        return ans;
    }
};
