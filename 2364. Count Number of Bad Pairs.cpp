class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for (int i = 0; i<n; i++) {
            mpp[nums[i] - i]++;
        }

        long long ans = 1ll*n*(n-1)/2;
        for (auto it: mpp) {
            int cnt = it.second; 
            if (cnt > 1) {
                ans -= 1ll*cnt*(cnt-1)/2;
            }
        }

        return ans;
    }
};
