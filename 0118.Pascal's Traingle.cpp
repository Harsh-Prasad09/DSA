class Solution {
public:
    vector<int> returnRow(int n){
        vector<int> ans;
        int num = 1;
        ans.push_back(num);
        for (int i =1; i<n ;i++){
            num = num * (n - i);
            num = num / i;
            ans.push_back(num);
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++){
            ans.push_back(returnRow(i));
        }
        return ans;
    }
};
