class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        unordered_map<int, int> color;
        int n = queries.size();
        for (int i = 0;i <n; i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if (mpp.find(u) == mpp.end()){
                mpp[u] = v;
                color[v]++;  
            }
            else{
                color[mpp[u]]--;
                if (color[mpp[u]] == 0) color.erase(mpp[u]);
                mpp[u] = v;
                color[v]++;
            }
            ans.push_back(color.size());
        }
        return ans;
    }
};
