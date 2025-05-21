class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> arr(n, 0);

        for (vector<int> &query: queries) {
            int start = query[0];
            int end = query[1];

            arr[start]++;
            if (end+1 < n) arr[end+1]--;
        }

        for (int i = 1; i<n; i++) arr[i] += arr[i-1];

        for (int i = 0; i<n; i++) {
            if (arr[i] < nums[i]) return false;
        }

        return true;
    }
};
