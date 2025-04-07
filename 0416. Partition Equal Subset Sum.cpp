class Solution {
public:
    bool f(int idx, int sum, vector<int> &nums, vector<vector<int>> &dp) {
        if (idx == 0) return nums[idx] == sum;
        if (sum == 0) return true;

        if (dp[idx][sum] != -1) return dp[idx][sum];

        bool notpick = f(idx-1, sum, nums, dp);
        bool pick = false;
        if (nums[idx] <= sum) pick = f(idx-1, sum-nums[idx], nums, dp);

        return dp[idx][sum] = pick || notpick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(nums.size(), vector<int>(sum+1, -1));
        return (sum % 2 == 1)? false : f(nums.size()-1, sum/2, nums, dp);
    }
};
