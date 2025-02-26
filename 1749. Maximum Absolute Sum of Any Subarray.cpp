class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN, mini = INT_MAX;
        int sum = 0;

        for (int num : nums) {
            sum += num;
            sum = max(sum, 0);
            maxi = max(maxi, sum);
        }

        sum = 0;
        for (int num : nums) {
            sum += num;
            sum = min(sum, 0);
            mini = min(mini, sum);
        }

        mini = -mini;
        return max(maxi, mini);
    }
};
