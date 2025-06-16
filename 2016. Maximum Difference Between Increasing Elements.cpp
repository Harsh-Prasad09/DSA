class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxGreater(n);
        maxGreater[n-1] = -1e9;

        int maxi = nums[n-1];
        for (int i = n-2; i>=0; i--) {
            maxi = max(maxi, nums[i]);
            maxGreater[i] = (maxi > nums[i])? maxi: -1e9;
        }

        int ans = -1;
        for (int i = 0; i<n; i++) {
            ans = max(ans, maxGreater[i] - nums[i]);
        }

        return ans;
    }
};
