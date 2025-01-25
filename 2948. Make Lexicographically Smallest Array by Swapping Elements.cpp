class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int idx = 0;
        unordered_map<int, int> grp;
        grp[temp[0]] = idx;

        unordered_map<int, vector<int>> mpp;
        mpp[idx] = {temp[0]};

        for (int i = 1; i<n; i++) {
            if (temp[i] - temp[i-1] > limit) idx++;

            grp[temp[i]] = idx;
            if (mpp.find(idx) == mpp.end()) mpp[idx] = {};

            mpp[idx].push_back(temp[i]);
        }

        for (auto it: mpp) {
            vector<int> arr = it.second;
            sort(arr.begin(), arr.end(), greater<int>());
            it.second = arr;
        }

        for (int i = n-1; i>=0; i--) {
            int group = grp[nums[i]];
            nums[i] = mpp[group].back();
            mpp[group].pop_back();
        }

        return nums;
    }
};
